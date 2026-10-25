// Send Temperature Sensor Data through Bluetooth following a Bluetooth request (DHT11 - HC-05 - Arduino Uno)
// Including Adafruit DHT11 Library and SoftwareSerial for Bluetooth Serial communication 
#include "DHT.h"
#include <SoftwareSerial.h>
// Pin for the DHT sensor
#define DHTPIN 9
// Define DHTTYPE DHT11, DHT22    
#define DHTTYPE DHT11

// Defining PIN connectors for HC-05 Transmit / Receive
SoftwareSerial BTSerial(10, 11); // RX | TX

// Create instance for the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Setup
void setup(void)
{
  dht.begin();
  BTSerial.begin(9600);

}

void loop(void)
{
    
    // Get command
    if (BTSerial.available()) {

      // Read command
      byte c = BTSerial.read ();

      // If a measurement is requested, measure data and send it back
      if (c == 'm'){

          int h = (int)dht.readHumidity();
          int t = (int)dht.readTemperature();

          // Send data (temperature,humidity)
          BTSerial.println(String(t) + "," + String(h));
      }
  }
}
