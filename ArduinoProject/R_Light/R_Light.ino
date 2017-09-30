
int val;
long int result;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);
  result =  map(val,0,1023,0,10);
  Serial.println(result);
  delay(4000);
}
