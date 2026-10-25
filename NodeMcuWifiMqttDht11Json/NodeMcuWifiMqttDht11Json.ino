// Sketch for NodeMCU 1.0 ESP-12E: publishing DHT11 data to MQTT broker over Wifi.
// Arduino library for ESP-12, ESP-12E.
#include <ESP8266WiFi.h>
// Using PubSubClient library by one of the creators of Node-RED, Nick O'Leary.
#include <PubSubClient.h>
// dht lib http://arduino.cc/playground/Main/DHTLib Version: 0.1.00.
#include <dht.h>

dht DHT;

// Define NodeMCU D0 (USER) pin as temperature input data pin of DHT11.
#define DHT11_PIN D0

// Update these with your network values:
const char* ssid = "SSID_NAME";
const char* password = "WIFI_PASSWORD";
const char* mqtt_server = "MQTT_BROKER_HOSTNAME";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {
   delay(100);
  // Connecting to the WiFi network:
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

// Callback: configuration as a subscriber for remote control (Not mandatory)
// You can remove the declaration below and its call in void setup.
void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Command is: [");
  Serial.print(topic);
  int p =(char)payload[0]-'0';
  int chk = DHT.read11(DHT11_PIN);
  // if MQTT broker sends a 0 message return humidity
  if(p==0) 
  {
    Serial.println("to show humidity!]");
    Serial.print("{\"Humidity\":");
    Serial.print(DHT.humidity, 1);
    Serial.println("}");
  } 
  // if MQTT sends a 1 message return temperature
  if(p==1)
  {
   Serial.println("to show temperature!]");
  int chk = DHT.read11(DHT11_PIN);
   Serial.print("{\"Temperature\":");
   Serial.print(DHT.temperature, 1);
   Serial.println("}");
  }
  Serial.println();
} //end callback

void reconnect() {
  // Loop until reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random MQTT client ID:
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect:
    // if your MQTT broker has clientID,username and password
    // change following client.connect function with your (clientId,userName,passWord)
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
     // Connected to MQTT broker, subscribing to command topic:
      client.subscribe("nodemcu");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying.
      delay(6000);
    }
  }
} //end reconnect()

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("{\"Temperature\":");
  Serial.print(DHT.temperature);
  Serial.print(",\"Humidity\":");
  Serial.print(DHT.humidity);
  Serial.println("}");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  // read DHT11 sensor every 6 seconds
  // Return data in a JSON friendly format:
  if (now - lastMsg > 6000) {
     lastMsg = now;
     int chk = DHT.read11(DHT11_PIN);
     String msg="{\"Temperature\":";
     msg=msg+DHT.temperature;
     msg=msg+",\"Humidity\":";
     msg=msg+DHT.humidity ;
     msg=msg+"}";
     char message[58];
     msg.toCharArray(message,58);
     Serial.println(message);
     // Publish sensor data to the MQTT broker:
    client.publish("extTemperature", message);
  }
}