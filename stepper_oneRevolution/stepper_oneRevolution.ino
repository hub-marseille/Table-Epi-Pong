//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)


int stepPin = A0;  //connect pin 13 to step
int dirPin = A1;  // connect pin 12 to dir
int ebl = 38;
int a = 0;     //  gen counter
#include <Encoder.h>
long oldPosition  = 0;
Encoder myEnc(3, 2);

void setup() 
{                
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ebl, OUTPUT);
  digitalWrite(ebl, LOW);  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular directi
  long newPosition = myEnc.read()/2;

    if (newPosition > oldPosition)
    {
      digitalWrite(dirPin,HIGH);
      for(int x = 0; x < (newPosition - oldPosition); x++)
      {
        //Changes the rotations direction
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500); 
      }
      oldPosition = newPosition;
    }
    else if (newPosition < oldPosition)
    {
      digitalWrite(dirPin,LOW);
      for(int x = 0; x < (oldPosition - newPosition); x++)
      {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(500);
        digitalWrite(dirPin,LOW); //Changes the rotations direction
      }
    oldPosition = newPosition;
    Serial.println(newPosition);
  } 
}
