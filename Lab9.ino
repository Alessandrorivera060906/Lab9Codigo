#define BLYNK_TEMPLATE_ID "TMPL208i1cMUU"
#define BLYNK_TEMPLATE_NAME "labioT"
#define BLYNK_AUTH_TOKEN "p9Kqra-DBtGpSPxmPbgaJW_UTbFBt3mF"
#define BLYNK_DEBUG
#define LED_PIN 5

#define ANALOG_PIN A0

#include <BlynkSimpleStream.h>

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN; 

BLYNK_WRITE(V1) {
  int value = param.asInt(); // Recibe datos del Switch desde Blynk Cloud: 0 o 1
  
  digitalWrite(LED_PIN, value);
}

void sendValue()
{
  int ambientLight = analogRead(ANALOG_PIN);
  Blynk.virtualWrite(V0, ambientLight); // Envia datos al Gauge del Blynk Cloud
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(Serial, auth);  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(4,OUTPUT);
  timer.setInterval(500L, sendValue); // Envia datos cada 0.5 seg
}

void loop()
{
  
  Blynk.run();
  timer.run();
  int ambientLight = analogRead(A0);
  if (ambientLight > 600 && ambientLight < 1023) {
    tone(4, 1000);
  } else {
    noTone(4);  
  }
}
