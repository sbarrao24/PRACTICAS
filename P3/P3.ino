#include <stdint.h>

//definer pines

uint8_t red_led = 19; //led rojo
uint8_t button = 23; //botón

bool led_state = false; //estado del led

void setup() {
  // configurar pines
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(button, INPUT_PULLUP); //inicializar el pin botón
  //pullup = 1 es reposo y 0 es pulsando

  //Inicializar led apagado
  digitalWrite(red_led, LOW);
}

void loop() {
  if(digitalRead(button) == LOW) { //cuando se pulsa el botón
    delay(50);//retraso para evitar fallos
    led_state =! led_state; //intercambio del valor del led
    digitalWrite(red_led, led_state); //apagado o encendido del led
  }

}
