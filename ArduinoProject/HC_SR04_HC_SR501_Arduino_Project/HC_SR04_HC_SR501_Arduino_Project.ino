#include "SR04.h"

//interrupt
#define INTERRUPT_PIN  0

//HC-SR501
#define HW_OUT 3

//HC-SR04
#define TRIG_PIN 4
#define ECHO_PIN 5


SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
float distance;//ultrasonic Distance(float)
long a;//ultrasonic Distance(Int)
int in;// Is HC-SR501 Input



void setup() {
    pinMode(HW_OUT,INPUT);
    pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN,LOW);
    Serial.begin(9600);
}


void loop() {
    //delay(1000);
    in = digitalRead(HW_OUT);
    if(in==0){//There must is No Person
        digitalWrite(LED_BUILTIN,LOW);
        while(true){//2.4S
            in = digitalRead(HW_OUT);
            if(in==1){
                break;
            }else{ 
                delay(400);
            }
            Serial.println("N"); 
       }
   }else if(in==1){//Maybe has Person
             int i=0;
             while(i<40){//16S   Output Distance
                 digitalWrite(LED_BUILTIN,HIGH);
                 printDistance();
                 delay(400);
                 digitalWrite(LED_BUILTIN,LOW);
                 i++;
                 in = digitalRead(HW_OUT);
                 if(in==0){//3S delay
                     int k=0;
                     while(k<6){
                         printDistance(); 
                         delay(500);
                         k++;
                         in=digitalRead(HW_OUT);
                         if(in==1){
                             break;
                         }
                     }
                     break;
                 }
             }
    }
}

//Print Distance
void printDistance(){
    a = sr04.Distance();
    distance = a*0.01;
    if(distance<=4.5){
        
        Serial.print("Y");
        Serial.println(distance);
    }
}


