#define BLYNK_TEMPLATE_ID "TMPL6-ITFcnKD"
#define BLYNK_TEMPLATE_NAME "Temperature - Humidity Monitor And Control LED"
#define BLYNK_AUTH_TOKEN "5vF2sAinlyKbw1HdfK-3teOJL8AtxKkv"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>

#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "chicanquamon";  
char pass[] = "123456789";  

BlynkTimer timer;


#define DHTPIN 2 //Connect Out pin to D4 in NODE MCU
#define LEDPIN 4 //Connect LED
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);
}
void setup()
{   
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
  }

void loop()
{
  Blynk.run();
  timer.run();
 }