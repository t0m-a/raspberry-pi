#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int dryValue = 1024;
int wetValue = 38;
int friendlyDryValue = 0;
int friendlyWetValue = 100;

// Update these with values suitable for your network.
const char* ssid = "SSID_NAME";
const char* password = "WIFI_PASSWORD";
const char* mqtt_server = "MQTT_SERVER_HOSTNAME";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

// Wifi connexion
void setup_wifi() {
   delay(100);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Reconnexion to MQTT broker
void reconnect() {
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // If broker requires Auth: (client.connect(clientId,userName,passWord))
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      client.subscribe("nodemcu");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(6000);
    }
  }
} //end reconnect()

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  int rawValue = analogRead(A0);
  Serial.print("{\"Raw\":");
  Serial.print(rawValue);
  int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
  Serial.print(",\"Percentage\":");
  Serial.print(friendlyValue);
  Serial.println("}");
  delay(500);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  // read M21 sensor every 6 seconds
  if (now - lastMsg > 6000) {
     lastMsg = now;
     int rawValue = analogRead(A0);
     String msg="{\"Raw\":";
     msg=msg+rawValue;
     int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);
     msg=msg+",\"Percentage\":";
     msg=msg+friendlyValue;
     msg=msg+"}";
     char message[58];
     msg.toCharArray(message,58);
     Serial.println(message);
     // publish sensor data to MQTT broker
    client.publish("Plants Humidity 2", message);
  }
}