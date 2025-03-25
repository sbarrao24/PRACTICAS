#include <stdint.h>

// Definir pines
#define pinPIR 18 // sensor de movimiento PIR
#define pinBuzzer 21  //buzzer

void setup() {
    pinMode(pinPIR, INPUT);   //configurar el PIR
    pinMode(pinBuzzer, OUTPUT); // configurar el buzzer
    Serial.begin(115200);     //comunicación baudios
}

void loop() {
    uint64_t estadoPIR = digitalRead(pinPIR); //sensor PIR
    Serial.println(estadoPIR); 

    if (estadoPIR == HIGH) { //con movimiento enciende buzzer sino lo apaga
        digitalWrite(pinBuzzer, HIGH); 
    } else { 
        digitalWrite(pinBuzzer, LOW); 
    }

    delay(100);
}






