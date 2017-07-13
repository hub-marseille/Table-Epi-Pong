/*
 * By guigur 2017
 * EpiPong Project
 */

int       stepPin = A0;
int       dirPin = A1;
int       ebl = 38;
int       a = 0;

#include  <Encoder.h>
long oldPosition  = 0;
Encoder myEnc(3, 2);

void      setup() 
{                
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ebl, OUTPUT);
  digitalWrite(ebl, LOW);  
  Serial.begin(9600);
}

void      loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular directi
  long newPosition = myEnc.read()/4;

    if (newPosition > oldPosition)
    {
      digitalWrite(dirPin,HIGH);
      for(int x = 0; x < (newPosition - oldPosition); x++)
      {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(400); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(400); 
      }
      oldPosition = newPosition;
    }
    else if (newPosition < oldPosition)
    {
      digitalWrite(dirPin,LOW);
      for(int x = 0; x < (oldPosition - newPosition); x++)
      {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(400);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(400);
        digitalWrite(dirPin,LOW);
      }
    oldPosition = newPosition;
    Serial.println(newPosition);
  } 
}
