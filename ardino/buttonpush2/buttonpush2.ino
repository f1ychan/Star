 boolean pushbutton1;
 boolean pushbutton2;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
pushbutton1=digitalRead(2);
pushbutton2=digitalRead(4);
if(pushbutton1==1||pushbutton2==1){
  digitalWrite(13,HIGH);
}
else{
   digitalWrite(13,LOW);
  
}

}
