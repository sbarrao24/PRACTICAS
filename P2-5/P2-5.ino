#include <stdint.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //librerías especiales para el IR y OLED

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
 //supuesto reset
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SENSOR_IR 15  //pin del IR va a 5V este sensor infrarrojos

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("inicio OLED");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(SENSOR_IR, INPUT);
}

void loop() {
    uint32_t estadoSensor = digitalRead(SENSOR_IR);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 32);
    
    if (estadoSensor == LOW) {  //si detecta un obstáculo impreme una cosa sino otra
        display.println("Hola ALBA!");
    } else {
        display.println("Adios ALBA");
    }
    
    display.display();
    delay(500);
}