#include <stdint.h>

//Definir pines para cada uno de los leds
uint8_t red_led = 21;
uint8_t green_led = 18;

//Inicialización de la variable previous millis tipo de datos entero
uint64_t previous_millis_red = 0;
uint64_t previous_millis_green = 0;

//Declaración de la variable intervalo de tiempo, tipo de dato entero
uint64_t red_interval = 1000;
uint64_t green_interval = 2000;


//Void setup se utiliza para configurarciones en la placa utilzada
void setup() { 
//Inicializamos la comunicación del puerto serie 
  Serial.begin (112500);
//configuramos los puestos como salidas
  pinMode (red_led ,OUTPUT);
  pinMode (green_led ,OUTPUT);
//Iniciamos los led apagados
  digitalWrite (red_led, LOW);
  digitalWrite (green_led, LOW);
}

//Función principal
void loop() {
// Milis es una funcion para mostrar el tiempo en milisegundos 
// Almacenamos el valor en milisegundos desde que el led rojo y verde cambiaron de estado

  uint64_t actual_millis = millis ();
  if (actual_millis - previous_millis_red > red_interval) {
    previous_millis_red = millis();
    if (digitalRead (red_led)){
      digitalWrite (red_led, false);
    }else {
      digitalWrite (red_led,true);
    }
  }
  if(actual_millis - previous_millis_green > green_interval) {
    previous_millis_green = millis();
    if (digitalRead (green_led)){
      digitalWrite (green_led, false);
    }else {
      digitalWrite (green_led,true);
    }
  }
}