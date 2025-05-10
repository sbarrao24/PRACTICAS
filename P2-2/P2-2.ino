#include <stdint.h>

// Definir pines
#define pinLDR 2// fotoresistor 
#define pinRed 23 //led rojo
#define pinGreen 18 //led verde
#define pinBlue 4//led azul

uint8_t valorLuz = 0; //almacena la lectura del fotoresistor
uint8_t umbralLuz = 100; // umbral de luz ``experimento´´

void setup() {
    Serial.begin(115200);  // inicia comunicación en baudios
    pinMode(pinLDR, INPUT);  // configura el fotoresistor
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pinBlue, OUTPUT);
}

void loop() {
    valorLuz = analogRead(pinLDR); //valor del fotoresistor
    Serial.println(valorLuz);      //valor en el monitor serie

    if (valorLuz < umbralLuz) {  //si hay poca luz enciende el led
        analogWrite(pinRed, 0);
        analogWrite(pinGreen, 0);
        analogWrite(pinBlue, 255);
    } else {  //si hay luz apagar el led
        analogWrite(pinRed, 255);
        analogWrite(pinGreen, 0);
        analogWrite(pinBlue, 0);
    }

    //delay(500); 
}