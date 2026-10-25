// Send Moisture Sensor Data through Bluetooth (M21 - HC-05 - Arduino Uno and Najo)
// Including SoftwareSerial for Bluetooth Serial communication. Formatting result string in JSON style.
#include <SoftwareSerial.h>

// Defining PIN connectors for HC-05 Transmit / Receive
SoftwareSerial BTSerial(10, 11); // RX | TX

int dryValue = 320;
int wetValue = 670;
int friendlyDryValue = 0;
int friendlyWetValue = 100;
void setup() {
  BTSerial.begin(9600);
}
void loop() {
  int rawValue = analogRead(A0);
  BTSerial.print("{\"Raw\":");
  BTSerial.print(rawValue);
  
  int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  
  BTSerial.print(",\"Percentage\":");
  BTSerial.print(friendlyValue);
  BTSerial.println("}");
  
  delay(500);
}
