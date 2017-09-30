#include "SR04.h"
#define TRIG_PIN 2
#define ECHO_PIN 3
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
float distance;

//Only for HC-SR04

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600);
}

void loop() {
   a=sr04.Distance();
   distance=a*0.01;
   if(distance<4.5){
       Serial.println(distance);
   }
   digitalWrite(LED_BUILTIN, HIGH);
   delay(1000);
   digitalWrite(LED_BUILTIN, LOW);
}
