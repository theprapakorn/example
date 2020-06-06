#include <AntoIO.h>
#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11

const char *ssid = "korn";
const char *pass = "0897263093";
const char *user = "theprapakorn";
const char *token = "JvHKHOtNyn1twtVvBVrrhNEbWCzVXyLlcU1N2v86";
const char *thing = "DTH_TEST";

AntoIO anto(user, token, thing);
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Anto library version: ");
  Serial.println(anto.getVersion());
  Serial.print("\nTrying to connect ");
  Serial.print(ssid);
  Serial.println("...");
  anto.begin(ssid, pass, messageReceived);
  Serial.println("\nConnected Anto done");
  dht.begin();
}

void loop() {
  anto.mqtt.loop();
  if (!anto.mqtt.isConnected())
    Serial.println("Disconnected");
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();
  Serial.print("TEMP: ");
  Serial.println(temp);
  Serial.print("HUMID: ");
  Serial.println(humid);
  if(temp >= 0){
     anto.pub("Temp",temp);           
  }
  if(humid >= 0){
     anto.pub("Humid",humid);
  }
  delay(1000);
}
void messageReceived(String thing, String channel, String payload) {
  Serial.print("Recieved: ");
  Serial.print(thing);
  Serial.print("/");
  Serial.print(channel);
  Serial.print("-> ");
  Serial.println(payload);
}
