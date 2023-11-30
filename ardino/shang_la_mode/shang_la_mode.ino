void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
pinMode(13,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal=digitalRead(2);
  Serial.println(sensorVal);
  if(sensorVal == HIGH){
    pinMode(12,OUTPUT); }
   else{
   pinMode(13,OUTPUT);
   }

}
