// Send Temperature Sensor Data through Bluetooth following a Bluetooth request (DHT11 - HC-05 - Arduino Uno)
// Including DHT11 Library and SoftwareSerial for Bluetooth Serial communication. Formatting result string in JSON style. 
#include <dht.h>
#include <SoftwareSerial.h>
// Pin for the DHT sensor
#define DHT11_PIN 9

// Defining PIN connectors for HC-05 Transmit / Receive
SoftwareSerial BTSerial(10, 11); // RX | TX

// Create instance for the DHT sensor
dht DHT;

// Setup
void setup(void)
{

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

          int chk = DHT.read11(DHT11_PIN);

          // Send data (temperature,humidity)
          BTSerial.print("{\"Temperature\":");
          BTSerial.print(DHT.temperature);
          BTSerial.print(",\"Humidity\":");
          BTSerial.print(DHT.humidity);
          BTSerial.println("}");
      }
  }
}
