#include <stdint.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "time.h"

//WiFi
//const char* ssid = "DIGIFIBRA-TZfC";
//const char* password = "3yHcu7GKQ2H3";
const char* ssid = "ALUMNOS_CICLOS";
const char* password = "Ciclos2025sz?";

//hora española
const char* ntpServer = "es.pool.ntp.org";
const long gmtOffset_sec = 3600;
const int32_t daylightOffset_sec = 0;

//mis datos para la aplicación (usuario, clave, servidor y puerto)
const char* mqtt_username = "sbarrao";
const char* mqtt_password = "1234";
const char* mqtt_server = "broker.emqx.io";
const int32_t mqtt_port = 1883;

//creacción de objetos
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

//const int32_t ledPin = 2; //Pin led GPIO2 

//para recibir datos MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el topico: ");
  Serial.println(topic);

//convertir string a payload
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensaje: ");
  Serial.println(message);

  //se comprueba el encender o apagar el led
  if (message == "1") {
    digitalWrite(LED_BUILTIN, HIGH); //Encender
    Serial.println("LED ON");
  } else if (message == "0") {
    digitalWrite(LED_BUILTIN, LOW); //Apagar
    Serial.println("LED OFF");
  }
}

//Reconectar a MQTT
void reconnect() {
  while (!mqtt_client.connected()) {
    Serial.print("Conectando a MQTT...");
    String client_id = "esp32-client-" + String(WiFi.macAddress());

    if (mqtt_client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Conectado!");
      mqtt_client.subscribe("sensor/boton"); //para recibir datos y suscribirse al tópico
    } else {
      Serial.print("Error, codigo: ");
      Serial.println(mqtt_client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);//baudios

  //Configurar pin del led
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); //Apagado en el inicio

  //Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("WiFi conectado");

  //Configuración NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  //Configuración MQTT
  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(callback); //Asignar función callback
}

void loop() {
  if (!mqtt_client.connected()) {
    reconnect();
  }
  mqtt_client.loop();

  //Obtener y enviar hora actual
  struct tm timeinfo;//Guarda el tiempo
  if (getLocalTime(&timeinfo)) {
    char hora[30];//se declara array ``hora´´ con 30 caracteres
    strftime(hora, sizeof(hora), "%H:%M:%S - %d/%m/%Y", &timeinfo);//sizeof(hora) devuelve 30 espacios disponibles para guardar caracteres
    Serial.println(hora);
    mqtt_client.publish("esp32/hora", hora); //Publicar hora
  } else {
    Serial.println("Error al obtener la hora");
  }

  delay(5000); //publicar cada 5 segundos
}