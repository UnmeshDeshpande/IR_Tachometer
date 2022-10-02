int s;   //Reciever Status
int p = 0; //Calculates rpm only once.Else loop messes up the code
unsigned int irpm = 0;
unsigned int arpm = 0;
unsigned int rot_time = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT); //Sensor data
  
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH); //Sensor Vcc
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  s=0;
  s = digitalRead(8);
  if (s == 1)
  {
    p = 0;
    rot_time=rot_time+1;
    delay(1);
    
  }
  else {
    if (p == 0) {
      p = 1;
      irpm = (60000 / rot_time);
      if (irpm <= 60000)
      {
        Serial.println(irpm);
       
        }
        rot_time = 0;
      
    }
    
  }
}
