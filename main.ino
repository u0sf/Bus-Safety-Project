// BUS SAFETY PROJECT
// Students seating are detected and Red LED is on, otherwise green LED is on
// When everyone have left the bus, and no one is sitting anymore, the
// Ultrasonic Sensor, detects if a student is 75cm away, 
// in case someone is left
// The set distance is up to 75cm away, but can be adjusted in the program.
// When a student is detected within 75cm, an alarm will sound
// and will automatically call the driver's number.

#define CUSTOM_SETTINGS
#define INCLUDE_PHONE_SHIELD  
#include <OneSheeld.h>
#define  echoPin 11
#define  trigPin 12
long duration, distance;
#include "pitches.h"
int melody[] = {NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,NOTE_C5, NOTE_G4,NOTE_C5, NOTE_G4};
int noteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8};
#define  R0  7
#define  G0  6
#define  R1  5
#define  G1  4
#define  LDR0 A0    //1 leg A0 & ResISTOR, 1 leg 5V,  1 leg of Res in GND 
#define  LDR1 A1    //1 leg A1 & ResISTOR, 1 leg 5V,  1 leg of Res in GND

void alarm(void)     
{
  //Play the alarm sound
  for (int k=0; k<5; k++){
   for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);    
    digitalWrite(13,1);   //red LED will be ON    
    }  
  } 
}

void setup() {
  OneSheeld.begin();
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  

  pinMode(R0, OUTPUT);
  pinMode(G0, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(LDR0, INPUT);
  pinMode(LDR1, INPUT);  

}


void loop() { 
   int x0, x1;  
   x0=analogRead(LDR0);
   delay(50);
   x1=analogRead(LDR1);
   delay(50);
   delay(500);
   if(x1<300){
     digitalWrite(G0, 0);       
     digitalWrite(R0, 1);      
   }
   else{
     digitalWrite(G0, 1);       
     digitalWrite(R0, 0); 
   }
   
   if(x0<700){
     digitalWrite(G1, 0);       
     digitalWrite(R1, 1);   
   }
   else{
     digitalWrite(G1, 1);       
     digitalWrite(R1, 0); 
   }
   while(x0>=700 && x1>=300)
   {
     int j=0;
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     duration=pulseIn(echoPin, HIGH);
     distance=duration/58.2;
     delay(20);
     if(distance <= 75){
       //A student is detected 75cm or less than 75cm away from ultrasonic sensor
       Phone.call("0553925740");
      /* Wait for 300 ms. */
      OneSheeld.delay(300);
      alarm();    //sound the alarm
  }
  else{
     //No student is detected 75 cm away
     delay(500);
     digitalWrite(13, 0);   // red LED will be OFF    
     delay(250);
  }
  noTone(8);
  delay(100);

   x0=analogRead(LDR0);      //check if a student is sitting in seat 0
   delay(50);
   x1=analogRead(LDR1);      //check if a student is sitting in seat 1
   delay(50);
  }
}