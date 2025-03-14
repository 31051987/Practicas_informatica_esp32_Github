#include <stdint.h>
//Definición de pines para el led y para el interruptor
uint8_t green_led = 18;
uint8_t button = 21;

bool led_state= false;

void setup() {
  // Configuración de los pines y la comunicación
  Serial.begin (112500);
  pinMode (green_led, OUTPUT);
  pinMode (button,INPUT_PULLUP); //Configuración de la resistencia interna como pull up
  //Pullup es que en reposo la entrada es 1

  digitalWrite(green_led, LOW); //Inicia el led apagado
}

void loop() {
  if(digitalRead (button) == LOW){
    delay (5); //Introducimos un delay para evitar el rebote
    led_state =! led_state;//Intercambiamos el valor del estado del led
    digitalWrite(green_led, led_state);
  }

}
