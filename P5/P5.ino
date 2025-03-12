#include <stdint.h>

// Definir pine
uint8_t red_1 = 16, yellow_1 = 4, green_1 = 0;  // Semáforo 1
uint8_t red_2 = 25, yellow_2 = 33, green_2 = 32;  // Semáforo 2

// Variables de tiempo
uint64_t tiempo_cambio = 0;
uint64_t intervalo_verde = 10000;  // 10 seg en verde
uint64_t intervalo_amarillo = 2000; // 2 seg en amarillo
uint8_t estado = 0; //secuencia de semáforos

void setup() {
   //Configurar pines
 
 
  Serial.begin(9600);
  pinMode(red_1, OUTPUT);
  pinMode(yellow_1, OUTPUT);
  pinMode(green_1, OUTPUT);
  pinMode(red_2, OUTPUT);
  pinMode(yellow_2, OUTPUT);
  pinMode(green_2, OUTPUT);

  //Inicializar semáforos
  digitalWrite(red_1, LOW);
  digitalWrite(yellow_1, LOW);
  digitalWrite(green_1, HIGH);
  
  digitalWrite(red_2, HIGH);
  digitalWrite(yellow_2, LOW);
  digitalWrite(green_2, LOW);

  tiempo_cambio = millis();
}

void loop() {
  uint64_t tiempo_actual = millis();

  switch (estado) {
    case 0: //Semáforo 1 en verde - semáforo 2 en rojo
      if (tiempo_actual - tiempo_cambio >= intervalo_verde) {
        digitalWrite(green_1, LOW);
        digitalWrite(yellow_1, HIGH);
        estado = 1;
        tiempo_cambio = millis();
      }
      break;

    case 1: //Semáforo 1 en amarillo
      if (tiempo_actual - tiempo_cambio >= intervalo_amarillo) {
        digitalWrite(yellow_1, LOW);
        digitalWrite(red_1, HIGH);
        digitalWrite(red_2, LOW);
        digitalWrite(yellow_2, HIGH);
        estado = 2;
        tiempo_cambio = millis();
      }
      break;

    case 2: //Semáforo 2 en amarillo
      if (tiempo_actual - tiempo_cambio >= intervalo_amarillo) {
        digitalWrite(yellow_2, LOW);
        digitalWrite(green_2, HIGH);
        estado = 3;
        tiempo_cambio = millis();
      }
      break;

    case 3: //Semáforo 2 en verde - semáforo 1 en rojo
      if (tiempo_actual - tiempo_cambio >= intervalo_verde) {
        digitalWrite(green_2, LOW);
        digitalWrite(yellow_2, HIGH);
        estado = 4;
        tiempo_cambio = millis();
      }
      break;

    case 4: //Semáforo 2 en amarillo
      if (tiempo_actual - tiempo_cambio >= intervalo_amarillo) {
        digitalWrite(yellow_2, LOW);
        digitalWrite(red_2, HIGH);
        digitalWrite(red_1, LOW);
        digitalWrite(yellow_1, HIGH);
        estado = 5;
        tiempo_cambio = millis();
      }
      break;

    case 5: //Semáforo 1 en amarillo
      if (tiempo_actual - tiempo_cambio >= intervalo_amarillo) {
        digitalWrite(yellow_1, LOW);
        digitalWrite(green_1, HIGH);
        estado = 0;
        tiempo_cambio = millis();
      }
      break;
  }
}