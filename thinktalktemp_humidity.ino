#include <DHT.h>
#include <ESP8266WiFi.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
String apiKey         = "FGIT8L591Z4FXC6X";     // thingspeak API key, 
const char* ssid      = "korn";
const char* password  = "0897263093"; 
const char* server    = "api.thingspeak.com";

#define DHTPIN  D3
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
    
void setup() {
                  
  Serial.begin(115200);
  delay(10);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.print("DHT11 Test!");
  WiFi.begin(ssid, password);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}
void loop() {
   
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("DHT Failed!");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  if (client.connect(server,80)) {
    String  url = "/update?api_key="+ apiKey ;
            url += "&field1=" + (String)t;
            url += "&field2=" + (String)h;  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" + 
                   "Connection: close\r\n\r\n");
      lcd.setCursor(0, 0);
    lcd.print("Temp : ");
    lcd.setCursor(7, 0);
    lcd.print(t);
    lcd.setCursor(13, 0);
    lcd.print("*C");
    lcd.setCursor(0, 1);
    lcd.print("Humid : ");
    lcd.setCursor(8, 1);
    lcd.print(h);
    lcd.setCursor(14, 1);
    lcd.print("%"); 
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.print(" *C  and Humidity: "); 
    Serial.print(h);
    Serial.println("% "); 

  }
  client.stop();
  Serial.print("Waiting...");    
  delay(20000);  // thingspeak needs minimum 15 sec delay between updates
}
