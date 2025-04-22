#include <WiFi.h>
#include "time.h"

//WiFi clase o casa
//const char* ssid = "DIGIFIBRA-TZfC";
//const char* password = "3yHcu7GKQ2H3";
const char* ssid = "ALUMNOS_CICLOS";
const char* password = "Ciclos2025sz?";

const char* ntpServer = "es.pool.ntp.org";//conexión servidor
const int32_t gmtOffset_sec = 3600; //zona horaria
const int32_t daylightOffset_sec = 0; //horario de verano o invoierno

void setup() {
  Serial.begin(115200);//conexión en baudios
//conexión y configuración wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conexion a WiFi");
  }
  Serial.println("Conectado");
//funciones de configuración
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {  //lee los parámetros
    Serial.println(&timeinfo, "%H:%M:%S - %d/%m/%Y"); //hora y fecha
  } else {
    Serial.println("Error hora");
  }
  delay(5000);
}