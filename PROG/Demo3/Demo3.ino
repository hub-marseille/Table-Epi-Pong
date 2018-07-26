/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include <StepControl.h>


Stepper motor(3, 4);         // STEP pin: 2, DIR pin: 3 -> mot 4
StepControl<> controller;    // Use default settings 
Encoder myEnc(0, 1);
//   avoid using pins with LEDs attached
int target = 0;
int operationEnCours = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
        pinMode(8, OUTPUT);
      digitalWrite(8, LOW);
      motor.setAcceleration(2000);    // stp/s^2
      motor.setMaxSpeed(6000);         // stp/s
      motor.setPullInSpeed(200); //works fine @ 200
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if ((newPosition != oldPosition) && operationEnCours == 0) {
    oldPosition = newPosition;
    Serial.println(newPosition);
    target = newPosition/10;
      operationEnCours = 1;
  }

if (motor.getTargetRel != target)
{
 motor.setTargetRel(target);  // Set target position to 1000 steps from current position
  controller.move(motor);    // Do the move
  operationEnCours = 0;
}

  
  
}





