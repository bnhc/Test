#define ECHO_PIN 4
int in;

//Only for HC-SR501

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  Serial.begin(9600);
}



void loop() {
  in = digitalRead(ECHO_PIN);
  if(in==0){
    Serial.println("SR501_N");
    digitalWrite(LED_BUILTIN,LOW);
  }else if(in==1){
    Serial.println("SR501_Y");
    int i=0;
    while(i<7){
      //digitalWrite(LED_BUILTIN,HIGH);
      delay(400);
      //digitalWrite(LED_BUILTIN,LOW);
      //delay(200);
      i++;
    }
  }                                     
  delay(1000);
}
