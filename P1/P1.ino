#include <stdint.h>

//definer pine

uint8_t red_led = 19; //led rojo
uint8_t green_led = 4; //led verde

void setup() {
  // inicio puerto
  Serial.begin(112500);//comunicación en baudios
  //configurar pines
  pinMode(red_led, OUTPUT);
   pinMode(green_led, OUTPUT);

}

void loop() {
  // encender led rojo y apagar led verde
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, LOW);
  delay(1000); //esperar 1 segundo

  digitalWrite(red_led, LOW);
  digitalWrite(green_led, HIGH);
  delay(1000); //esperar 1 segundo
}

