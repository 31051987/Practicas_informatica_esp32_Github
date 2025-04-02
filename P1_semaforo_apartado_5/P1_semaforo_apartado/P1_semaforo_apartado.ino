#include <stdint.h>


//Definir pines para cada uno de los leds
uint8_t red_led_traffic_light_one = 23 ;
uint8_t green_led_traffic_light_one = 21 ;
uint8_t yellow_led_traffic_light_one = 22 ;

uint8_t red_led_traffic_light_two = 4 ;
uint8_t green_led_traffic_light_two = 2 ;
uint8_t yellow_led_traffic_light_two= 15;

// Tiempos de duración de cada estado,verde ,ambar y rojo (en milisegundos)
uint64_t greenTime = 5000;  // 5 segundos
uint64_t yellowTime = 2000; // 2 segundos
uint64_t redTime = 7000;    // 7 segundos

//Void setup se utiliza para configurarciones en la placa utilzada
void setup() { 
//Inicializamos la comunicación del puerto serie y configuramos los puestos como salidas
  Serial.begin (112500);

  pinMode (red_led_traffic_light_one ,OUTPUT);
  pinMode (green_led_traffic_light_one ,OUTPUT);
  pinMode (yellow_led_traffic_light_one,OUTPUT);

  pinMode (red_led_traffic_light_two ,OUTPUT);
  pinMode (green_led_traffic_light_two ,OUTPUT);
  pinMode (yellow_led_traffic_light_two,OUTPUT);

//Inicialización de los semáforos
  digitalWrite(red_led_traffic_light_one, HIGH);  // Semáforo 1 en rojo
  digitalWrite(green_led_traffic_light_two, HIGH);
}

void loop() {
  // Semáforo 1 en verde, Semáforo 2 en rojo
  digitalWrite(green_led_traffic_light_one, HIGH);
  digitalWrite(red_led_traffic_light_two, HIGH);
  digitalWrite(red_led_traffic_light_one, LOW);
  digitalWrite(green_led_traffic_light_two, LOW);
  delay(greenTime); 

  // Semáforo 1 en amarillo, Semáforo 2 en rojo
  digitalWrite(green_led_traffic_light_one, LOW);
  digitalWrite(yellow_led_traffic_light_one, HIGH);
  delay(yellowTime);

  // Semáforo 1 en rojo, Semáforo 2 en verde
  digitalWrite(yellow_led_traffic_light_one, LOW);
  digitalWrite(red_led_traffic_light_one, HIGH);
  digitalWrite(red_led_traffic_light_two, LOW);
  digitalWrite(green_led_traffic_light_two, HIGH);
  delay(greenTime);

  // Semáforo 1 en rojo, Semáforo 2 en amarillo
  digitalWrite(green_led_traffic_light_two, LOW);
  digitalWrite(yellow_led_traffic_light_two, HIGH);
  delay(yellowTime);

  // Semáforo 1 en rojo, semáforo 2 en amarillo
  digitalWrite(yellow_led_traffic_light_two, LOW);
  digitalWrite(red_led_traffic_light_two, HIGH);
  delay (1000);
}
 