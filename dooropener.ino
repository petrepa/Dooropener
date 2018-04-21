#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
 
const char* ssid = "[YOURSSID]";
const char* password =  "[YOURPW]";
const char* mqttServer = "[YOURMQTTBROKER]";
const int mqttPort = 1883;
const char* mqttUser = "[MQTTUSERNAME]"; //blank if you don't have a username
const char* mqttPassword = "[MQTTPW]"; //blank if you don't have a password
 
WiFiClient espClient;
PubSubClient client(espClient);

Servo servo;
 
void setup() {
  Serial.begin(115200); 
  WiFi.begin(ssid, password);

  servo.attach(D4);
  servo.write(70);
  servo.detach();
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish("esp/test", "Hello from ESP8266");
  client.subscribe("esp/test");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  if(*payload == 49){
    rotServo();
    Serial.println();
    Serial.print("Roterar servo");
    client.publish("esp/test", "0");
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}

void rotServo(){
  servo.attach(D4);
  servo.write(70);
  delay(1000);
  servo.write(175);
  delay(2000);
  servo.write(70);
  delay(3000);
  servo.detach();
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}