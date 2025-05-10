#include <stdint.h>

#define pinLed1 19 // led
#define pinLed2 16 // led
#define pinLed3 5 // led
#define potenciometro 23 // potenciómetro
#define buzzer 21 // buzzer
uint8_t portValue = 0;

void setup() {
    pinMode(pinLed1, OUTPUT);
    pinMode(pinLed2, OUTPUT);
    pinMode(pinLed3, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    uint8_t portValue = analogRead(potenciometro); // valor del potenciómetro
    Serial.println(portValue);

// encendido y regulación de led y buzzer
    if (portValue >= 1365) {  
        // Luz baja: led1 encendido y buzzer apagado
        digitalWrite(pinLed1, HIGH);
    }else if(portValue < 1365){
    digitalWrite(pinLed1, LOW);
        tone(buzzer, 440);
        delay(1000);
    } 
     if (portValue >= 2730) {  
        // Luz baja: led2 encendido y buzzer apagado
        digitalWrite(pinLed2, HIGH);
    }else if(portValue < 2730){
    digitalWrite(pinLed2, LOW);
        noTone(buzzer);
        delay(1000);
    } 
  if (portValue >= 4095) {  
        // Luz baja: led1 encendido y buzzer encendido
        digitalWrite(pinLed3, HIGH);
    }else if(portValue < 4095){
    digitalWrite(pinLed3, LOW);
        tone(buzzer, 523, 300);//se progrman 523Hz y 300ms
        
    }

    delay(500);
}