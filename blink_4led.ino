#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "7d6ORYUln4G8PmWQ2-fNxiuSRb592NOW";
char ssid[] = "korn";
char pass[] = "0897263093";
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
}
