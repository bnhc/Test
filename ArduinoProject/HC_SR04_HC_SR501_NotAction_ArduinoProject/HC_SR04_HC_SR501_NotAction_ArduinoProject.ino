#include "SR04.h"

//HC-SR501
#define HW_OUT 3

//HC-SR04
#define TRIG_PIN 4
#define ECHO_PIN 5

/**
 * Note Send Data Type Like This:
 * GuangMin State
 * Person State
 * distance State
 * 
 * Data list : 5|0|1.5
 */

//LED-Sensor

#define LED_PIN 0

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
float distance;
long a;
int in;
long int  result; 

void setup() {
  pinMode(HW_OUT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int tmp = analogRead(LED_PIN);
  result =map(tmp,0,1024,0,10);
  in = digitalRead(HW_OUT);
  a = sr04.Distance();
  distance = a * 0.01;
  if (distance > 4.5) {
    distance = 4.5;
  }
  if (in == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.print(result);
  Serial.print("|");
  Serial.print(in);
  Serial.print("|");
  Serial.println(distance);
  delay(1000);
}
