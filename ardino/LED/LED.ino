void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(1,HIGH);
  delay(1000);
  for(int i=1;i<=8;i++){
    digitalWrite(i,LOW);
  }


  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(1,HIGH);
}
