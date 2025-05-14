#include <stdint.h>

// Definición de pines
int8_t movement_sensor_Pin = 32;  // Pin del sensor HC-SR501
int8_t buzzerPin = 25; // Pin del buzzer

void setup() {
  // Configuración de pines
  pinMode(movement_sensor_Pin, INPUT); // Configura el pin del sensor como entrada
  pinMode(buzzerPin, OUTPUT); // Configura el pin del buzzer como salida

  // Inicializa el buzzer apagado
  digitalWrite(buzzerPin, LOW);

  // Inicializa la velcidad comunicación serial  (baudios)
  Serial.begin(115200);
 
}

void loop() {
  // Lee el estado del sensor HC-SR501
  int32_t movementDetected = digitalRead(movement_sensor_Pin);

 // Si se detecta movimiento, activa el buzzer
  if (movementDetected == HIGH) {
 
    digitalWrite(buzzerPin, HIGH);

// Si no se detecta movimiento, apaga el buzzer
  } else {
 
    digitalWrite(buzzerPin, LOW);
    
  }


  delay(100);
}
