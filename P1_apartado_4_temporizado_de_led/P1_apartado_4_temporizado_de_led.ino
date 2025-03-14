#include <stdint.h>


// Definición de pines
uint8_t green_led = 18;      // Pin del LED
uint8_t p1 = 21;       // Pin del pulsador P1
uint8_t p2 = 23;       // Pin del pulsador P2

// Variables de estado
bool ledState = false;      // Estado del LED (encendido/apagado)
uint32_t startTime = 0; // Tiempo de inicio del contador
uint32_t interval = 10000; // Intervalo de 10 segundos

void setup() {
  // Configuración de pines
  pinMode(green_led, OUTPUT);
  pinMode(p1, INPUT_PULLUP); // Usamos resistencia pull-up interna
  pinMode(p2, INPUT_PULLUP); // Usamos resistencia pull-up interna

  // Inicialmente el LED está apagado
  digitalWrite(green_led, LOW);
}

void loop() {
  // Leer el estado de los pulsadores
  bool p1State = digitalRead(p1);
  bool p2State = digitalRead(p2);

  // Si se pulsa P1 y el LED está apagado, encender el LED y empezar el contador
  if (p1State == LOW && !ledState) { //Invertimos el valor lógico del estado del led
    ledState = true;
    digitalWrite(green_led, HIGH);
    startTime = millis();
  }

  // Si el LED está encendido y pasan 10 segundos el led se apaga
  if (ledState) {
    // Verificamos si han pasado 10 segundos y apagamos el led
    if (millis() - startTime >= interval) {
      ledState = false;
      digitalWrite(green_led, LOW);
    }

    // Si se pulsa P2, apagar el LED y reiniciar el contador
    if (p2State == LOW) {
      ledState = false;
      digitalWrite(green_led, LOW);
    }

    // Si se pulsa P1 nuevamente, reiniciar el contador
    if (p1State == LOW) {
      startTime = millis();
    }
  }
}
  