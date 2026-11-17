// Lentes inteligentes - ESP32-CAM
//
// 1. Se conecta al Wi-Fi y enciende la cámara.
// 2. Cada segundo toma una foto y se la manda al servidor (app.py), donde YOLO dice si hay persona o animal.
// 3. También muestra la cámara en vivo en http://<IP de la cámara> (útil para acomodarla).
// 4. Si se cae el Wi-Fi, se reconecta sola; si la cámara falla varias veces seguidas, se reinicia.
//
// Placa en Arduino IDE: "AI Thinker ESP32-CAM". Monitor Serial a 115200 baudios.
// El Wi-Fi y la IP del servidor van en credenciales.h

#include "esp_camera.h"
#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "credenciales.h"  // nombre y clave del Wi-Fi, IP del servidor (no se sube a GitHub)

// ==========================
// AJUSTES
// ==========================

// Pausa mínima entre fotos. Es casi cero: la siguiente foto sale apenas el servidor responde la anterior,
// así que el límite real es lo que tarda el viaje foto -> servidor -> respuesta.
const unsigned long INTERVALO_MS = 50;
const int ESPERA_SERVIDOR_MS = 5000;              // el servidor ya tiene YOLO cargado al encender
const unsigned long REINTENTO_WIFI_MS = 5000;     // cada cuánto se reintenta si se cae el Wi-Fi
const int FALLOS_PARA_REINICIAR = 5;              // fotos fallidas seguidas antes de reiniciar la placa
const int PIN_FLASH = 4;                          // LED blanco de la cámara (se deja apagado)

const String urlYolo = String("http://") + SERVIDOR_IP + ":" + SERVIDOR_PUERTO + "/api/imagen";

WebServer server(80);

bool camaraLista = false;
int fallosSeguidos = 0;
unsigned long ultimoEnvio = 0;
unsigned long ultimoReintentoWiFi = 0;

// ==========================
// CÁMARA (AI Thinker ESP32-CAM)
// ==========================

bool iniciarCamara() {
  camera_config_t config = {};

  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;

  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;
  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;
  config.pin_sccb_sda = 26;
  config.pin_sccb_scl = 27;
  config.pin_pwdn = 32;
  config.pin_reset = -1;

  config.xclk_freq_hz = 10000000;            // 10 MHz: más estable (a 20 MHz se reiniciaba con FB-OVF)
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;         // 640x480: YOLO reconoce mejor que con 320x240
  config.jpeg_quality = 12;
  config.fb_count = 1;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY; // solo toma foto cuando se la piden

  if (psramFound()) {
    config.fb_location = CAMERA_FB_IN_PSRAM;
  } else {
    Serial.println("PSRAM no encontrada: se usa 320x240");
    config.frame_size = FRAMESIZE_QVGA;
    config.fb_location = CAMERA_FB_IN_DRAM;
  }

  esp_err_t error = esp_camera_init(&config);
  if (error != ESP_OK) {
    Serial.print("ERROR CAMARA: 0x");
    Serial.println(error, HEX);
    return false;
  }
  return true;
}

// Cuenta las fotos fallidas; si son muchas seguidas, reinicia la placa
void anotarFallo() {
  fallosSeguidos++;
  if (fallosSeguidos >= FALLOS_PARA_REINICIAR) {
    Serial.println("Demasiados errores seguidos, reiniciando...");
    delay(500);
    ESP.restart();
  }
}

// ==========================
// PÁGINA WEB (ver la cámara en vivo)
// ==========================

void paginaInicio() {
  server.send(200, "text/html",
    "<html><head><meta name='viewport' content='width=device-width, initial-scale=1'></head>"
    "<body style='background:black;color:white;text-align:center;'>"
    "<h2>ESP32-CAM</h2>"
    "<img id='foto' src='/foto' style='width:100%;max-width:640px;'>"
    "<script>setInterval(function(){"
    "document.getElementById('foto').src='/foto?t='+Date.now();"
    "},1500);</script>"
    "</body></html>");
}

void enviarFoto() {
  camera_fb_t* foto = esp_camera_fb_get();
  if (!foto) {
    server.send(500, "text/plain", "Error tomando foto");
    return;
  }
  server.sendHeader("Cache-Control", "no-store");
  server.setContentLength(foto->len);
  server.send(200, "image/jpeg", "");
  server.client().write(foto->buf, foto->len);
  esp_camera_fb_return(foto);
}

// ==========================
// MANDAR FOTO A YOLO
// ==========================

void mandarFotoAYolo() {
  camera_fb_t* foto = esp_camera_fb_get();
  if (!foto) {
    Serial.println("ERROR tomando foto para YOLO");
    anotarFallo();
    return;
  }

  HTTPClient http;
  http.begin(urlYolo);
  http.setTimeout(ESPERA_SERVIDOR_MS);
  http.addHeader("Content-Type", "image/jpeg");
  int codigo = http.POST(foto->buf, foto->len);
  esp_camera_fb_return(foto);

  if (codigo == 200) {
    // YOLO contesta algo como: {"tipo": "persona", "objetos": ["person"]}
    String respuesta = http.getString();
    fallosSeguidos = 0;
    if (respuesta.indexOf("\"persona\"") >= 0) Serial.println("YOLO: persona");
    else if (respuesta.indexOf("\"animal\"") >= 0) Serial.println("YOLO: animal");
    else Serial.println("YOLO: nada");
  } else {
    // Código negativo = no llegó al servidor (servidor apagado, IP equivocada o firewall)
    Serial.print("ERROR enviando a YOLO: ");
    Serial.println(http.errorToString(codigo));
  }
  http.end();
}

// ==========================
// SETUP Y LOOP
// ==========================

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  // evita que se reinicie cuando el Wi-Fi pide mucha corriente

  Serial.begin(115200);
  delay(1000);
  pinMode(PIN_FLASH, OUTPUT);
  digitalWrite(PIN_FLASH, LOW);

  Serial.println();
  Serial.println("======================");
  Serial.println("LENTES - ESP32-CAM");
  Serial.println("======================");

  // 1) Primero el Wi-Fi (si se enciende la cámara antes, a veces se reinicia)
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_NOMBRE, WIFI_CLAVE);
  Serial.print("Conectando a ");
  Serial.print(WIFI_NOMBRE);
  for (int i = 0; i < 40 && WiFi.status() != WL_CONNECTED; i++) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Wi-Fi conectado. IP de la camara: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Sin Wi-Fi por ahora, se sigue intentando...");
  }

  // 2) Después la cámara
  camaraLista = iniciarCamara();
  if (!camaraLista) {
    Serial.println("NO SE PUDO INICIAR LA CAMARA (revisen el cable plano). Reiniciando en 5 s...");
    delay(5000);
    ESP.restart();
  }
  Serial.println("CAMARA OK");

  server.on("/", paginaInicio);
  server.on("/foto", enviarFoto);
  server.begin();

  Serial.print("Mandando fotos a ");
  Serial.println(urlYolo);
}

void loop() {
  server.handleClient();

  if (WiFi.status() != WL_CONNECTED) {
    if (millis() - ultimoReintentoWiFi >= REINTENTO_WIFI_MS) {
      ultimoReintentoWiFi = millis();
      Serial.println("Wi-Fi caido, reconectando...");
      WiFi.reconnect();
    }
    return;
  }

  static bool avisoIP = false;
  if (!avisoIP) {
    Serial.print("Ver camara en vivo: http://");
    Serial.println(WiFi.localIP());
    avisoIP = true;
  }

  if (camaraLista && millis() - ultimoEnvio >= INTERVALO_MS) {
    ultimoEnvio = millis();
    mandarFotoAYolo();
  }

  delay(2);
}
