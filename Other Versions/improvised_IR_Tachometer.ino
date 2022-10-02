int stats=0;  //Status of receiver
int n=0;  //number of rotations
int pass=0;
int ttorotate=0;
float rpm=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  stats=digitalRead(8);
  
  if(stats==1)
  {
    digitalWrite(12,LOW);
    pass=0;
    ttorotate=ttorotate+10;
    
    
    delay(10);
  }
else
{
  digitalWrite(12,HIGH);

  if(pass==0){n=n+1;pass=1;rpm=60000/ttorotate;
  Serial.println(rpm);ttorotate=0;delay(30);}
  
  
  
}



}
