String comdata="";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1500000);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    comdata+=char(Serial.read());
    delay(2);
  }
  if(comdata.length()>0){
    Serial.println(comdata);
    comdata="";
  }
}
