#include <DHT.h>
#include <stdint.h>

// Definición de pines
int8_t DHTPIN = 33 ;      // Pin del sensor DHT11
#define DHTTYPE DHT11    // Tipo de sensor DHT
int8_t redled = 18 ;    // Pin del LED rojo
int8_t greenled = 4 ;    // Pin del LED verde
int8_t yellowled = 19 ;   // Pin del LED amarillo

// Inicialización del sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Configuración de pines de los LEDs como salidas
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);

  // Inicialización del sensor DHT
  dht.begin();

  // Inicialización de la comunicación serial para depuración
  Serial.begin(115200);
  
}

void loop() {
  // Lee la temperatura y la humedad
  float temperatura = dht.readTemperature(); // Lee la temperatura en °C
  float humedad = dht.readHumidity();       // Lee la humedad en %

  // Verifica si la lectura del sensor fue exitosa
  //isnan es una condición de verificacion de errores,"is not a number"
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11.");
    return;
  }

  // Muestra los valores en el monitor
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C, Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Apaga todos los LEDs inicialmente
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(yellowled, LOW);

  // Condiciones para activar los LEDs
  if (temperatura < 20) {
    digitalWrite(greenled, HIGH); // Activa el LED verde si la temperatura es menor a 20°C
  }
  if (temperatura > 15) {
    digitalWrite(yellowled, HIGH); // Activa el LED amarillo si la temperatura es mayor a 15°C
  }
  if (temperatura < 20 && temperatura > 15 && humedad < 50) {
    digitalWrite(redled, HIGH); // Activa el LED rojo si se cumplen ambas condiciones de temperatura y la humedad es menor a 50%
  }

  // Espera 2 segundos antes de la siguiente lectura
  delay(2000);
}
