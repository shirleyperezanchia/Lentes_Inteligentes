// Lentes inteligentes - ESP32 PRINCIPAL (sensor HC-SR04 + buzzer)
//
// 1. Mide la distancia 5 veces por segundo (3 lecturas y se queda con la del medio, para ignorar errores).
// 2. Si hay algo a menos de 150 cm, pita; más rápido mientras más cerca.
// 3. Si eso se queda quieto 2 segundos (una pared, alguien hablándote), se calla.
//    Si se acerca, vuelve a sonar. A menos de 25 cm suena siempre, para no chocar.
// 4. Si la cámara ve una persona o un animal (aunque esté a más de 150 cm), da 2 pitidos una sola vez.
// 5. Todo lo que es Wi-Fi y servidor corre en otra tarea, en el otro núcleo del ESP32:
//    así el sensor y el buzzer nunca se traban, aunque el servidor esté apagado o la red esté lenta.
// 6. Cada 10 segundos le avisa al servidor que sigue encendido (para la página).
//
// Conexiones:
//   Buzzer +  -> GPIO 18 (D18)     HC-SR04 TRIG -> GPIO 13 (D13)     HC-SR04 ECHO -> GPIO 21 (D21)
//
// Placa en Arduino IDE: "ESP32 Dev Module". Monitor Serial a 115200 baudios.
// El Wi-Fi y la IP del servidor van en credenciales.h

#include <WiFi.h>
#include <HTTPClient.h>
#include "credenciales.h"

// ==========================
// PINES
// ==========================

const int PIN_BUZZER = 18;
const int PIN_TRIG = 13;
const int PIN_ECHO = 21;

// ==========================
// AJUSTES (se pueden cambiar después de las pruebas)
// ==========================

// false = se le manda una señal de 2.7 kHz con tone(): funciona con buzzer pasivo y también con activo.
// true = solo se le da corriente: sirve únicamente para buzzer activo (con el pasivo no suena).
const bool BUZZER_ACTIVO = false;
const int FRECUENCIA_PASIVO = 2700;                // Hz (los piezo suenan más fuerte cerca de 2.7 kHz)

const unsigned long INTERVALO_MEDICION_MS = 200;   // 5 mediciones por segundo
const unsigned long INTERVALO_CONSULTA_MS = 1000;  // cada cuánto se pregunta qué vio la cámara
const unsigned long INTERVALO_LATIDO_MS = 10000;   // cada cuánto se avisa que los lentes siguen encendidos
const unsigned long ESPERA_ECO_US = 30000;         // sin eco en 30 ms = nada a menos de ~5 m
const int ESPERA_SERVIDOR_MS = 1500;               // máximo para conectar y para responder

const float DISTANCIA_MAXIMA_CM = 150;   // más lejos de esto, silencio
const float DISTANCIA_PELIGRO_CM = 25;   // más cerca de esto suena siempre, aunque esté quieto
const float TOLERANCIA_CM = 25;          // cambios menores a esto se toman como ruido (una persona nunca está 100% quieta)
const unsigned long TIEMPO_ESTABLE_MS = 2000;  // quieto por 2 s = se silencia
const int LECTURAS_FILTRO = 5;           // se usa la mediana de las últimas 5 mediciones (1 segundo)
const int LECTURAS_PARA_MOVIMIENTO = 3;  // tiene que verse movido 3 veces seguidas para contar como movimiento
const int LECTURAS_PARA_PERDER = 8;      // sin eco por 1.6 s = ya no hay nada (la ropa a veces no devuelve el eco)

const int DURACION_PITIDO_MS = 100;      // pitidos cortos para que el ritmo rápido se distinga
const int PITIDOS_AVISO_CAMARA = 2;
const int SEGUNDOS_PARA_OLVIDAR = 3;     // la cámara tiene que dejar de ver a la persona 3 s para avisar de nuevo
const bool MOSTRAR_DISTANCIA = false;    // true = imprime cada medición en el Monitor Serial (para probar el sensor)

// ==========================
// MÁQUINA DE ESTADOS
// ==========================
// SIN_OBSTACULO: no hay nada a menos de DISTANCIA_MAXIMA_CM -> silencio
// ALERTANDO:     hay un obstáculo y está cambiando de distancia -> suena
// ESTABLE:       el obstáculo lleva TIEMPO_ESTABLE_MS sin moverse -> silencio

enum Estado { SIN_OBSTACULO, ALERTANDO, ESTABLE };
enum Tipo { OBSTACULO, PERSONA, ANIMAL };
const char* NOMBRE_TIPO[] = { "obstaculo", "persona", "animal" };

Estado estado = SIN_OBSTACULO;
float distanciaReferencia = 0;        // distancia cuando el obstáculo dejó de moverse
float ultimaDistancia = -1;           // última distancia filtrada
unsigned long inicioQuieto = 0;       // desde cuándo está quieto
float historial[LECTURAS_FILTRO];     // últimas mediciones válidas, para el filtro
int cantidadHistorial = 0;
int indiceHistorial = 0;
int lecturasMovido = 0;               // mediciones seguidas viendo la distancia cambiada
int lecturasSinObstaculo = 0;         // mediciones seguidas sin ver nada

// Lo escribe la tarea del servidor y lo lee el loop (por eso es volatile)
volatile Tipo tipoVisto = OBSTACULO;  // lo que vio la cámara hace poco

bool camaraYaAviso = false;           // ya se avisó de la persona/animal que la cámara está viendo
int segundosSinVer = 0;

unsigned long ultimaMedicion = 0;
unsigned long ultimaRevisionCamara = 0;
unsigned long proximoPitido = 0;

// Buzzer sin delay(): así el sensor sigue midiendo mientras suena
bool buzzerSonando = false;
unsigned long apagarBuzzerEn = 0;
int pitidosPendientes = 0;
unsigned long proximoPitidoRafaga = 0;

// Detecciones que esperan ser enviadas al servidor (el loop las deja aquí, la tarea del servidor las manda)
struct Deteccion {
  float distancia;   // < 0 = la cámara la vio pero está más lejos de lo que mide el sensor
  Tipo tipo;
};
QueueHandle_t colaDetecciones;

String urlResultado;
String urlDeteccion;
String urlEstado;

// ==========================
// SENSOR
// ==========================

// Una lectura: distancia en cm, o -1 si el eco no volvió
float medirUnaVez() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  unsigned long duracion = pulseIn(PIN_ECHO, HIGH, ESPERA_ECO_US);
  if (duracion == 0) {
    return -1;
  }
  return duracion * 0.0343 / 2;  // velocidad del sonido; entre 2 porque va y vuelve
}

// 3 lecturas y se queda con la del medio: una lectura mala sola no dispara ni apaga la alerta
float medirDistancia() {
  float a = medirUnaVez();
  delay(10);
  float b = medirUnaVez();
  delay(10);
  float c = medirUnaVez();
  if (a > b) { float t = a; a = b; b = t; }
  if (b > c) { float t = b; b = c; c = t; }
  if (a > b) { float t = a; a = b; b = t; }
  return b;
}

// Agrega una medición y devuelve la mediana de las últimas: quita los saltos de un solo instante
float filtrarDistancia(float lectura) {
  historial[indiceHistorial] = lectura;
  indiceHistorial = (indiceHistorial + 1) % LECTURAS_FILTRO;
  if (cantidadHistorial < LECTURAS_FILTRO) {
    cantidadHistorial++;
  }

  float ordenadas[LECTURAS_FILTRO];
  for (int i = 0; i < cantidadHistorial; i++) {
    ordenadas[i] = historial[i];
  }
  for (int i = 1; i < cantidadHistorial; i++) {
    float valor = ordenadas[i];
    int j = i - 1;
    while (j >= 0 && ordenadas[j] > valor) {
      ordenadas[j + 1] = ordenadas[j];
      j--;
    }
    ordenadas[j + 1] = valor;
  }
  return ordenadas[cantidadHistorial / 2];
}

// ==========================
// BUZZER
// ==========================

void encenderBuzzer() {
  if (BUZZER_ACTIVO) digitalWrite(PIN_BUZZER, HIGH);
  else tone(PIN_BUZZER, FRECUENCIA_PASIVO);
  buzzerSonando = true;
  apagarBuzzerEn = millis() + DURACION_PITIDO_MS;
}

void apagarBuzzer() {
  if (BUZZER_ACTIVO) digitalWrite(PIN_BUZZER, LOW);
  else noTone(PIN_BUZZER);
  buzzerSonando = false;
}

// Se llama en cada vuelta del loop: apaga el pitido a tiempo y suelta los pitidos pendientes
void atenderBuzzer() {
  if (buzzerSonando && millis() >= apagarBuzzerEn) {
    apagarBuzzer();
  }
  if (!buzzerSonando && pitidosPendientes > 0 && millis() >= proximoPitidoRafaga) {
    encenderBuzzer();
    pitidosPendientes--;
    proximoPitidoRafaga = millis() + DURACION_PITIDO_MS + 120;
  }
}

// Tiempo entre pitidos según la distancia: más cerca = más rápido
unsigned long intervaloPitido(float distancia) {
  if (distancia < DISTANCIA_PELIGRO_CM) return 150;  // muy rápido
  if (distancia < 50) return 220;                    // rápido
  if (distancia < 100) return 350;                   // medio
  return 550;                                        // lento (100 - 150 cm)
}

void sonarSegunDistancia(float distancia) {
  if (buzzerSonando || millis() < proximoPitido) {
    return;
  }
  encenderBuzzer();
  proximoPitido = millis() + intervaloPitido(distancia);
}

// ==========================
// SERVIDOR (corre en su propia tarea, en el núcleo 0)
// ==========================

// Deja la detección en la cola; nunca espera, para no frenar el sensor
void registrarDeteccion(float distancia, Tipo tipo) {
  Deteccion d = { distancia, tipo };
  xQueueSend(colaDetecciones, &d, 0);
}

void enviarDeteccion(const Deteccion& d) {
  HTTPClient http;
  http.begin(urlDeteccion);
  http.setConnectTimeout(ESPERA_SERVIDOR_MS);
  http.setTimeout(ESPERA_SERVIDOR_MS);
  http.addHeader("Content-Type", "application/json");
  String valor = d.distancia > 0 ? String(d.distancia, 1) : "null";
  http.POST("{\"distancia\": " + valor + ", \"tipo\": \"" + NOMBRE_TIPO[d.tipo] + "\"}");
  http.end();
}

// Pregunta al servidor qué vio la cámara en los últimos segundos
void consultarCamara() {
  HTTPClient http;
  http.begin(urlResultado);
  http.setConnectTimeout(ESPERA_SERVIDOR_MS);
  http.setTimeout(ESPERA_SERVIDOR_MS);
  Tipo nuevo = OBSTACULO;

  if (http.GET() == 200) {
    // Respuesta: {"animal": false, "persona": true, "segundos": 0.8, "tipo": "persona"}
    String respuesta = http.getString();
    respuesta.replace(" ", "");
    respuesta.replace("\n", "");
    if (respuesta.indexOf("\"persona\":true") >= 0) nuevo = PERSONA;
    else if (respuesta.indexOf("\"animal\":true") >= 0) nuevo = ANIMAL;
  }
  http.end();
  tipoVisto = nuevo;
}

// Le avisa al servidor que los lentes siguen encendidos; devuelve el código HTTP (200 = el servidor respondió)
int enviarLatido() {
  HTTPClient http;
  http.begin(urlEstado);
  http.setConnectTimeout(ESPERA_SERVIDOR_MS);
  http.setTimeout(ESPERA_SERVIDOR_MS);
  http.addHeader("Content-Type", "application/json");
  int codigo = http.POST("{}");
  http.end();
  return codigo;
}

void tareaServidor(void*) {
  unsigned long ultimaConsulta = 0;
  unsigned long ultimoLatido = 0;
  unsigned long ultimoAvisoSinWiFi = 0;

  for (;;) {
    if (WiFi.status() != WL_CONNECTED) {
      tipoVisto = OBSTACULO;
      if (millis() - ultimoAvisoSinWiFi >= 5000) {
        ultimoAvisoSinWiFi = millis();
        Serial.print("Sin Wi-Fi: intentando conectar a ");
        Serial.println(WIFI_NOMBRE);
      }
      vTaskDelay(pdMS_TO_TICKS(500));
      continue;
    }

    Deteccion d;
    while (xQueueReceive(colaDetecciones, &d, 0) == pdTRUE) {
      enviarDeteccion(d);
    }
    if (millis() - ultimaConsulta >= INTERVALO_CONSULTA_MS) {
      ultimaConsulta = millis();
      consultarCamara();
    }
    if (ultimoLatido == 0 || millis() - ultimoLatido >= INTERVALO_LATIDO_MS) {
      ultimoLatido = millis();
      int codigo = enviarLatido();
      Serial.print("Wi-Fi OK (IP ");
      Serial.print(WiFi.localIP());
      Serial.print(") | Servidor ");
      Serial.print(SERVIDOR_IP);
      Serial.println(codigo == 200 ? ": OK" : ": NO RESPONDE (revisar IP, red o firewall)");
    }
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

// ==========================
// LÓGICA PRINCIPAL (loop, núcleo 1)
// ==========================

// Una vez por segundo: si la cámara ve una persona o animal nuevo, da el aviso
void revisarCamara() {
  Tipo visto = tipoVisto;
  if (visto == OBSTACULO) {
    segundosSinVer++;
    if (segundosSinVer >= SEGUNDOS_PARA_OLVIDAR) {
      camaraYaAviso = false;
    }
    return;
  }
  segundosSinVer = 0;
  if (camaraYaAviso) {
    return;
  }
  camaraYaAviso = true;
  Serial.print("AVISO: la camara ve ");
  Serial.println(NOMBRE_TIPO[visto]);
  if (estado != ALERTANDO) {
    pitidosPendientes = PITIDOS_AVISO_CAMARA;  // si ya está pitando por distancia, no hace falta
  }
  registrarDeteccion(estado == SIN_OBSTACULO ? -1 : ultimaDistancia, visto);
}

void cambiarEstado(Estado nuevo, float distancia) {
  if (nuevo == estado) {
    return;
  }
  estado = nuevo;
  lecturasMovido = 0;

  if (estado == SIN_OBSTACULO) {
    Serial.println("Estado: SIN OBSTACULO (silencio)");
  } else if (estado == ALERTANDO) {
    Serial.print("Estado: ALERTANDO a ");
    Serial.print(distancia, 1);
    Serial.println(" cm");
    distanciaReferencia = distancia;
    inicioQuieto = millis();
    proximoPitido = 0;  // que suene enseguida
    registrarDeteccion(distancia, tipoVisto);
  } else {
    Serial.println("Estado: ESTABLE (quieto, silencio)");
  }
}

void actualizar(float lectura) {
  bool hayObstaculo = lectura > 0 && lectura <= DISTANCIA_MAXIMA_CM;

  if (!hayObstaculo) {
    // Una lectura perdida no significa que se fue: se espera un momento antes de darlo por ido
    lecturasSinObstaculo++;
    if (lecturasSinObstaculo >= LECTURAS_PARA_PERDER) {
      cantidadHistorial = 0;
      indiceHistorial = 0;
      cambiarEstado(SIN_OBSTACULO, lectura);
    }
    if (estado == SIN_OBSTACULO) {
      return;
    }
  } else {
    lecturasSinObstaculo = 0;
    ultimaDistancia = filtrarDistancia(lectura);
  }

  float distancia = ultimaDistancia;
  bool lejosDeReferencia = fabs(distancia - distanciaReferencia) > TOLERANCIA_CM;
  lecturasMovido = lejosDeReferencia ? lecturasMovido + 1 : 0;
  bool seMovio = lecturasMovido >= LECTURAS_PARA_MOVIMIENTO;

  switch (estado) {
    case SIN_OBSTACULO:
      cambiarEstado(ALERTANDO, distancia);
      break;

    case ALERTANDO:
      if (seMovio) {
        // Sigue cambiando: se toma la nueva distancia como referencia y se reinicia el tiempo
        distanciaReferencia = distancia;
        inicioQuieto = millis();
        lecturasMovido = 0;
      } else if (millis() - inicioQuieto >= TIEMPO_ESTABLE_MS) {
        cambiarEstado(ESTABLE, distancia);
      }
      break;

    case ESTABLE:
      if (seMovio) {
        if (distancia < distanciaReferencia) {
          cambiarEstado(ALERTANDO, distancia);  // se acercó: vuelve a sonar
        } else {
          distanciaReferencia = distancia;      // se alejó: no hace falta avisar
          lecturasMovido = 0;
        }
      }
      break;
  }

  // Suena mientras alerta, y siempre que algo esté demasiado cerca
  if (estado == ALERTANDO || distancia < DISTANCIA_PELIGRO_CM) {
    sonarSegunDistancia(distancia);
  }
}

// ==========================
// SETUP Y LOOP
// ==========================

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  apagarBuzzer();

  Serial.println();
  Serial.println("==============================");
  Serial.println("LENTES INTELIGENTES - PRINCIPAL");
  Serial.println("==============================");

  String base = String("http://") + SERVIDOR_IP + ":" + SERVIDOR_PUERTO;
  urlResultado = base + "/api/resultado";
  urlDeteccion = base + "/api/deteccion";
  urlEstado = base + "/api/estado";

  // No se espera a que conecte: los lentes tienen que alertar aunque no haya Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_NOMBRE, WIFI_CLAVE);
  Serial.print("Conectando a ");
  Serial.println(WIFI_NOMBRE);

  colaDetecciones = xQueueCreate(10, sizeof(Deteccion));
  // El loop corre en el núcleo 1; la comunicación con el servidor va en el núcleo 0
  xTaskCreatePinnedToCore(tareaServidor, "servidor", 8192, nullptr, 1, nullptr, 0);

  // Pitido de inicio: avisa que los lentes encendieron
  pitidosPendientes = 1;
}

void loop() {
  atenderBuzzer();

  if (millis() - ultimaMedicion >= INTERVALO_MEDICION_MS) {
    ultimaMedicion = millis();
    float distancia = medirDistancia();
    if (MOSTRAR_DISTANCIA) {
      Serial.print("Distancia: ");
      if (distancia < 0) Serial.println("sin eco (nada cerca o sensor mal conectado)");
      else { Serial.print(distancia, 1); Serial.println(" cm"); }
    }
    actualizar(distancia);
  }

  if (millis() - ultimaRevisionCamara >= 1000) {
    ultimaRevisionCamara = millis();
    revisarCamara();
  }
}
