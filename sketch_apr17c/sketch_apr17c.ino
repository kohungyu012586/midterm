#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg; 

void setup() {
  Serial.begin(9600);
   byte numDigits =4;
   byte digitPins[] ={A2,A3,A4,A5};
   byte segmentPins[] = {2,3,4,5,6,7,8,9};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  Serial.print("10 04053071");
}

void loop() 
{
 
   int val,n=0,x;
    if (Serial.available()) 
    { 
         val = Serial.parseInt();
         if(val<=9999 && val >=0)
          {
            Serial.println(val);
            sevseg.setNumber(val);
            sevseg.refreshDisplay();
          }
     
        else 
       {
            Serial.println("range error");
       }
    }   
   else
   sevseg.refreshDisplay();
}
