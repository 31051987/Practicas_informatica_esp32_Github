#include <stdint.h>
// Definición de pines
int32_t potPin = 35;    // Pin del potenciómetro
int32_t redPin = 25;    // Pin del LED rojo
int32_t greenPin = 26;  // Pin del LED verde
int32_t bluePin = 27;   // Pin del LED azul
int32_t buzzerPin = 32; // Pin del buzzer

// Umbrales,limites (0 a 4095) el ADC es de 12 bits, por eso el valor de 4095
int32_t threshold1 = 1024; // Primer umbral (25% del rango)
int32_t threshold2 = 2048; // Segundo umbral (50% del rango)
int32_t threshold3 = 3072; // Tercer umbral (75% del rango)

// Variables
int32_t potValue = 0; // Valor leído del potenciómetro

void setup() {
  // Configurar pines
  pinMode(potPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Iniciar comunicación serial (opcional, para depuración)
  Serial.begin(115200);
}

void loop() {
  // Leer el valor del potenciómetro (0 - 4095)
  potValue = analogRead(potPin);
  
  // Control del RGB y el buzzer según el umbral
  // El valor de 255 sale de 2 a la 8 (8 bits) de la salida analogica 
  if (potValue < threshold1) {
    // LED rojo brillo bajo, buzzer a 100 Hz
    analogWrite(redPin, 64);    // Brillo bajo (64/255)
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 0);   
    tone(buzzerPin, 100);  
  } else if (potValue < threshold2) {
    // LED verde brillo medio, buzzer a 1000 Hz
    analogWrite(redPin, 0);     
    analogWrite(greenPin, 128); // Brillo medio (128/255)
    analogWrite(bluePin, 0);    
    tone(buzzerPin, 1000);      // Frecuencia de 1000 Hz
  } else if (potValue < threshold3) {
    // LED azul brillo alto, buzzer a 3000 Hz
    analogWrite(redPin, 0);     
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 192);  // Brillo alto (192/255)
    tone(buzzerPin, 3000);      // Frecuencia de 3000 Hz
  } else {
    //LED blanco (todos los colores), buzzer a 5000 Hz
    analogWrite(redPin, 255);   // Máximo brillo
    analogWrite(greenPin, 255);  // Máximo brillo
    analogWrite(bluePin, 255);   // Máximo brillo
    tone(buzzerPin, 5000);       // Frecuencia de 5000 Hz
  }

  delay (10);
}