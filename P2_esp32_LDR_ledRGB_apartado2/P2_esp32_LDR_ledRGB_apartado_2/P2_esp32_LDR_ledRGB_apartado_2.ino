#include <stdint.h>
// Definición de pines
int8_t ldrPin = 35;  // Pin de entrada analógica para el LDR
int8_t redPin = 25;  // Pin led rojo
int8_t greenPin = 26; // Pin led verde
int8_t bluePin = 27;  // Pin led azul

// umbral de luz
int32_t Threshold = 2500;

void setup() {
  // Configuración de pines
  pinMode(ldrPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Inicialmente, el LED está apagado
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  
  // Iniciar comunicación serial para depuración
  Serial.begin(115200);
}

void loop() {
  // Leer el valor del LDR
  int32_t lightValue = analogRead(ldrPin);
  
  // Controlar el LED RGB en función del valor de luz
  if (lightValue > Threshold) {
    // Si la luz es insuficiente, encender el LED (por ejemplo, en color blanco)
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  } else {
    // Si hay suficiente luz, apagar el LED
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  

  delay(100);
}
