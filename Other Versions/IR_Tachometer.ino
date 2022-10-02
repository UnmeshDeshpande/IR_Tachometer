int count;
int rpm;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8)==0)
  {
    count=count+1;
    digitalWrite(12,HIGH);
    delay(10);
    digitalWrite(13,LOW);
    
  }
  rpm=count/60;
  Serial.println(rpm);
  delay(10);
  digitalWrite(13,HIGH);

}
