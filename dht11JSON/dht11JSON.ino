// Send DHT11 serial data through USB, formatted in JSON style
// Library
#include <dht.h>
// Instanciate the sensor
dht DHT;
// DATA Pin from DHT11 to Arduino
#define DHT11_PIN 11

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("{\"Temperature\":");
  Serial.print(DHT.temperature);
  Serial.print(",\"Humidity\":");
  Serial.print(DHT.humidity);
  Serial.println("}");
  delay(5000);

  
}
