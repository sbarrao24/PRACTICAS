#include <DHT.h>  //Librerías para el sensor DHT
#include <DHT_U.h>

// Definir pines
#define pinGreen 21  //led verde
#define pinYellow 19  //led amarillo
#define pinRed 18  //led rojo

#define pinDHT 15 // pin del el DHT
#define DHTTYPE DHT11  //tipo de sensor DHT en el físico usamos el DHT11

DHT dht(pinDHT, DHTTYPE); //iniciar sensor DHT

void setup() {
    Serial.begin(115200);  //comunicación en baudios
    dht.begin();  //iniciar sensor

    //configuración pines
    pinMode(pinGreen, OUTPUT);
    pinMode(pinYellow, OUTPUT);
    pinMode(pinRed, OUTPUT);
}

void loop() {

    delay(2000);

    //temperatura y humedad
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity(); 

    //condiciones de los leds
    if (temperatura < 20) {
        digitalWrite(pinGreen, HIGH);
    } else {
        digitalWrite(pinGreen, LOW);
    }

    if (temperatura > 15) {
        digitalWrite(pinYellow, HIGH);
    } else {
        digitalWrite(pinYellow, LOW);
    }
    //temperatura menor a 20 y mayor de 15 con humedad menor al 50% enciende led rojo
    if (temperatura < 20 && temperatura > 15 && humedad < 50) {
        digitalWrite(pinRed, HIGH);
    } else {
        digitalWrite(pinRed, LOW);
    }

    delay(2000); 
}