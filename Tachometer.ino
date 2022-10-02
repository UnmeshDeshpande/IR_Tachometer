unsigned long int rpm, maxRPM;  //  DEFINE RPM AND MAXIMUM RPM
unsigned long time;         //  DEFINE TIME TAKEN TO COVER ONE REVOLUTION
int ledPin = 12;           //   STATUS LED
int led = 0,RPMlen , prevRPM;  //  INTEGERS TO STORE LED VALUE AND CURRENT RPM AND PREVIOUS RPM
int flag = 0;             //  A VARIABLE TO DETERMINE WHETHER THE LCD NEEDS TO BE CLEARED OR NOT
long prevtime = 0;       //  STORE IDLE TIME TO TOGGLE MENU
int REV;
    
 void setup()
 {
     Serial.begin(9600);     
    attachInterrupt(0, RPMCount, RISING);     //  ADD A HIGH PRIORITY ACTION ( AN INTERRUPT)  WHEN THE SENSOR GOES FROM LOW TO HIGH
     REV = 0;      //  START ALL THE VARIABLES FROM 0
     rpm = 0;
     time = 0;
     pinMode(ledPin, OUTPUT);
     pinMode(9, OUTPUT);           
     pinMode(10, OUTPUT);
     digitalWrite(9, HIGH);
     
     digitalWrite(10,HIGH);
          
     Serial.println("TACHOMETER");
    Serial.println("By Unmesh");
     delay(2000);
        
 }
 
 void loop()
 {
  long currtime = millis();                
  long idletime = currtime - prevtime;      
    
    if(REV >= 5 )                  //  IT WILL UPDATE AFETR EVERY 5 READINGS
   {
     
             
     if(flag==0)                     //  CLEAR THE LCD TO AVOID ANY GARBAGE TEXT
     {
       
       Serial.println("MEASURING");
       flag=1;                          //   AFTER FLAG = 1 , THE LOOP WILL NOT EXECUTE AGAIN
     }
     
     rpm = 30*1000/(millis() - time)*REV;       //  CALCULATE  RPM USING REVOLUTIONS AND ELAPSED TIME
     
     if(rpm > maxRPM)
     maxRPM = rpm;                             //  GET THE MAX RPM THROUGHOUT THE RUN
    
     time = millis();                            
     
     REV = 0;
     
     int x= rpm;                                //  CALCULATE NUMBER OF DIGITS IN RPM
     while(x!=0)
     {
       x = x/10;
       RPMlen++;
     }       
          
     
     
     if(RPMlen!=prevRPM)                             // IF THE RPM FALLS TO A LOWER NUMBER WITH LESS DIGITS , THE LCD WILL GET CLEARED
     {
       prevRPM = RPMlen;
       flag=0;
       Serial.println("MEASURING");
     }
     
     Serial.println(rpm,DEC);  //  PRINT RPM IN DECIMAL SYSTEM
     
 delay(500);
     
     prevtime = currtime;                        // RESET IDLETIME
    
   }
   
   if(idletime > 5000 )                      //  IF THERE ARE NO READING FOR 5 SEC , THE SCREEN WILL SHOW MAX RPM
   {
     
     if(flag==1)                            // CLEAR THE LCD
     {
       flag=0;
     }
     
 Serial.println("MaxRPM");
  Serial.println(maxRPM,DEC);       // DISPLAY MAX RPM
 Serial.println("MAX RPM");
     delay(2000);
    Serial.println("IDLESTATE");
   Serial.println("READY TO MEASURE");
     delay(2000);
     prevtime = currtime;
   }
     
 }
 
 void RPMCount()                                // EVERYTIME WHEN THE SENSOR GOES FROM LOW TO HIGH , THIS FUNCTION WILL BE INVOKED 
 {
   REV++;                                         // INCREASE REVOLUTIONS
   
   if (led == LOW)
   {
     
     led = HIGH;                                 //  TOGGLE STATUS LED
   } 
   
   else
   {
     led = LOW;
   }
   digitalWrite(ledPin, led);
 }
//////////////////////////////////////////////////////////////  END OF THE PROGRAM  ///////////////////////////////////////////////////////////////////////
