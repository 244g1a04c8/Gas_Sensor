//This is the sample code used for this tutorial. Try it!

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_TEMPLATE_ID "TMPL3SptnT01o"
#define BLYNK_TEMPLATE_NAME "MQ2"
#define BLYNK_AUTH_TOKEN "G31ZNKozISwsZUT68anlohB_nGu00KeC"
BlynkTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BLYNK_AUTH_TOKEN";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tomy";
char pass[] = "chenzheyuan";

#define MQ2 34
#define led1 16
#define led2 17
int sensorValue = 0;
boolean state = false;

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(MQ2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  timer.setInterval(1000L, sendUptime);
}

void sendUptime()
{
  
  sensorValue = analogRead(MQ2);
  Blynk.virtualWrite(V1, sensorValue);
  Serial.println(sensorValue);

  if (sensorValue > 600)
  {
    Blynk.notify("Gas Detected!");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  else
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}