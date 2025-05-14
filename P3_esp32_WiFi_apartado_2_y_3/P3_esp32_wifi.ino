#include <WiFi.h> //Librería utilizada para trabajar con WiFi en esp 32
#include "time.h" // Librería pra declarar funciones de fecha y hora
#include <stdint.h> // Librería para poder trabajar con nuemros enteros



// Configuración de WiFi
const char* ssid     = "MOVISTAR_D1EC";          // Red wIfI "ALUMNOS_CICLOS" o  MOVISTAR_D1EC
const char* password = "CDC574D8A95E6FDE69C1";   //contraseña "Ciclos2025sz?" o CDC574D8A95E6FDE69C1

// Configuración NTP
const char* ntpServer = "es.pool.ntp.org"; // Servidor NTP español
const int32_t  gmtOffset_sec = 3600;          // Offset GMT+1 (España )
const int32_t   daylightOffset_sec = 3600;// Offset para horario de verano

struct tm timeinfo;  //estructura para poder trabajar con ntp


void setup() {  //velocidad comunicación baudios
  Serial.begin(115200);
  
  // Conectar a WiFi
  Serial.println("Conectando a WiFI ");
  WiFi.begin(ssid, password);
  
  //bucle while mientras el wifi no este conectado
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("WiFi conectado");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Configurar e iniciar cliente NTP
  configTime (gmtOffset_sec, daylightOffset_sec, ntpServer);
 

}

void loop() {
  getLocalTime(&timeinfo); //obtine la hora local
  Serial.println (&timeinfo, "%d %m %Y %H: %M: %S"); //Imprime fecha y hora
  delay(1000);
}
