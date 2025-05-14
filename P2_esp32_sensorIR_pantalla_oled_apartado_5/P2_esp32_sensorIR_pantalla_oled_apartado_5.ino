//Librerías necesarias
#include <stdint.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 

//Ancho y alto de la pantalla
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//Definición pin sensor
int8_t sensor_IR = 33;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  //Config del pin
  pinMode(sensor_IR, INPUT);
  //Velocidad de comunicación
  Serial.begin(115200);
  delay(100);
  Serial.println("inicio OLED");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
}

void loop() {
    int32_t estadoSensor = digitalRead(sensor_IR);
  //configuración del texto mostrado
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 32);
    
    if (estadoSensor == LOW) {  //si detecta un obstáculo impreme una cosa sino otra
        display.println("Objeto detectado");
    } else {
        display.println("Sin obstaculos");
    }
    
    display.display();
    delay(500);
}