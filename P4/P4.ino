#include <stdint.h>

// Definir pines
uint8_t led_green = 4;   // Led
uint8_t button_1 = 19;    // Botón encender
uint8_t button_2 = 23;    // Botón apagar

// Variables del temporizador
uint64_t tiempo_encendido = 0;
bool led_encendido = false;
uint64_t intervalo = 10000; // 10 seg

void setup() {
  // Configurar pines
  Serial.begin(9600);
  pinMode(led_green, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);//inicializar el pin botón
  pinMode(button_2, INPUT_PULLUP);//inicializar el pin botón
  digitalWrite(led_green, LOW);  // inicializar led apagado
}

void loop() {
  uint64_t tiempo_actual = millis();

  // Si se pulsa button_1 se enciende el led y reinicia el temporizador
  if (digitalRead(button_1) == LOW) {
    delay(50); // retraso para evitar fallos
    led_encendido = true;
    tiempo_encendido = tiempo_actual;
    digitalWrite(led_green, HIGH);
  }

  // Si se pulsa button_2 se apaga el led
  if (digitalRead(button_2) == LOW) {
    delay(50);
    led_encendido = false;
    digitalWrite(led_green, LOW);
  }

  // Apagar el led si han pasado 10 segundos desde que se encendió
  if (led_encendido && (tiempo_actual - tiempo_encendido >= intervalo)) {
    led_encendido = false;
    digitalWrite(led_green, LOW);
  }
}