void setup() {
  // put your setup code here, to run once:
   pinMode(LED_BUILTIN,OUTPUT);
   attachInterrupt(1,stateChange,RISING);
   digitalWrite(LED_BUILTIN,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    
}

void stateChange(){
   digitalWrite(LED_BUILTIN,LOW);
   delay(2000);
}
