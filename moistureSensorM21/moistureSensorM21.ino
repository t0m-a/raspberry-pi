int dryValue = 320;
int wetValue = 670;
int friendlyDryValue = 0;
int friendlyWetValue = 100;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int rawValue = analogRead(A0);
  Serial.print("{\"Raw\":");
  Serial.print(rawValue);
  
  int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  
  Serial.print(",\"Percentage\":");
  Serial.print(friendlyValue);
  Serial.println("}");
  
  delay(500);
}
