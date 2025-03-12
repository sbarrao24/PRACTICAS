#include <stdint.h>

//definer pines
uint8_t red_led = 19; //led rojo
uint8_t green_led = 4; //led verde

//variables temporizadores
uint64_t previous_millis_red = 0;
uint64_t previous_millis_green = 0;

//intervalos de tiempo
uint64_t red_interval = 1000; //1seg
uint64_t green_interval = 2000; //2seg

void setup() {
  // configurar pines
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  //Inicializar leds apagados
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
}

void loop() {
  // 
  uint64_t actual_millis = millis(); //tiempo en milisegundos
  if(actual_millis - previous_millis_red > red_interval){ //actualiza el previous
    previous_millis_red = millis();
    if( digitalRead(red_led)){
      digitalWrite(red_led, false);
    }else{
      digitalWrite(red_led, true); //encendido o apagado del led rojo
    }
  }

    if(actual_millis - previous_millis_green > green_interval){
      previous_millis_green = millis();
      if(digitalRead(green_led)){
        digitalWrite(green_led, false);
      }else {
        digitalWrite(green_led, true); //encendido o apagado del led verde
      }
    }
}
