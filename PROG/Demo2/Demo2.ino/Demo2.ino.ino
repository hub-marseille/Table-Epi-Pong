/*==========================================================================
 * This is a minimal sketch showing the usage of TeensyStep
 *  
 * STEP Pulses on Pin 2    (can be any pin)
 * DIR  Signall on Pin 3   (can be any pin)
 * 
 * The target position is set to 1000 steps relative to the
 * current position. The move command of the controller 
 * moves the motor to the target position.  
 *  
 * Default parameters are 
 * Speed:          800 steps/s
 * Acceleration:  2500 steps/s^2
 * 
 * (slow, but good to start with since they will work on any normal stepper)
 *
 ===========================================================================*/

#include <StepControl.h>

Stepper motor(3, 4);         // STEP pin: 2, DIR pin: 3 -> mot 4
StepControl<> controller;    // Use default settings 
const int enableMot = 8;
const int endStpMot1 = 2;
void setup(){
      pinMode(enableMot, OUTPUT);
      digitalWrite(enableMot, LOW);

      
      motor.setAcceleration(2000);    // stp/s^2
      motor.setMaxSpeed(6000);         // stp/s
      motor.setPullInSpeed(200); //works fine @ 200
}




int initMot()
{

  
}

int target = 100;
void loop()
{
  motor.setTargetRel(target);  // Set target position to 1000 steps from current position
  controller.move(motor);    // Do the move
  if (target == 2000)
    target =  -2000;
  else
    target = 2000;
  delay(500);
}
