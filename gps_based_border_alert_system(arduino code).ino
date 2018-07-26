#include <TinyGPS++.h>
#include <SoftwareSerial.h>

const int buzzer = 9; //buzzer to arduino pin 9
static const int RXPin = 3, TXPin = 2;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
 Serial.begin(9600);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 ss.begin(GPSBaud);
}

void loop() {

 if(Serial.available())
 {
 int z = Serial.read();

 if(z==1)
 {
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 }

 if(z==2)
 {
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 }

  if(z==3)
 {
  
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,HIGH);
 digitalWrite(7,LOW);
 }

 if(z==4)
 {
 
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 }

 if(z==5)
 {
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 }
 }
 if (ss.available() > 0)
   { 
    if (gps.encode(ss.read()))
      {
       
        if (gps.location.isValid())
  {
   if( (gps.location.lat())>=28.5258 )     //lattitude location according to ur own location
    {
      
    
      tone(buzzer, 1000);
     digitalWrite(12,HIGH); //danger zone
     digitalWrite(13,LOW);  //safe zone
     }
     
 if( (gps.location.lat())<28.5257)
     {
      
    noTone(buzzer);
      digitalWrite(13,HIGH); //safe zone 
      digitalWrite(12,LOW);  //danger zone
      }
      
    
      }
  
        }
   }
  
}

