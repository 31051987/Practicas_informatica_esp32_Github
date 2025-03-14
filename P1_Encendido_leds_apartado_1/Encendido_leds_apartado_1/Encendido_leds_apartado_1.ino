#include <stdint.h>

//Definir pines para cada uno de los leds
uint8_t red_led = 21;
uint8_t green_led = 18;

//Void setup se utiliza para configurarciones en la placa utilzada
void setup() { 
//Inicializamos la comunicación del puerto serie y configuramos los puestos como salidas
  Serial.begin (112500);

  pinMode (red_led ,OUTPUT);
  pinMode (green_led ,OUTPUT);
}

//Función principal
void loop() {
//Encendido de led rojo y apagado de led verde
  digitalWrite (red_led, HIGH);
  digitalWrite (green_led, LOW);
  delay (1000); //Tiempo de espera

  //Encendido de led verde y apagado de led rojo
  digitalWrite (red_led, LOW);
  digitalWrite (green_led, HIGH);
  delay (2000); //Tiempo de espera

}
 