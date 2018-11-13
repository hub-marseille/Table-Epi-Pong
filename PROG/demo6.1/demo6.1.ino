#include <AccelStepper.h>
#include <Encoder.h>
#include "headers/Stepper.hpp"

AccelStepper stepper(AccelStepper::DRIVER, 3, 4);
Encoder knobLeft(0, 1);

const int enableMot = 8;
const int endStp = 2;

const int initSpeed = 1000; // The speed to find the endstop
const int maxSpeed = 6000;
const int maxAccelerationSpeed = 10000;

int posPaddle;
const int minSfyZone = 500;
const int maxSfyZone = 700;
const int railLength = 11000;
int playablePos = railLength-minSfyZone-maxSfyZone;

long posEncoder;
int endStpState = HIGH;

enum way {ASC, DESC, SAME};
int encoderWay = SAME;

void setup()
{
  // Debug stuff

  Serial.begin(115200);
  while (!Serial) {;}
  Serial.println("Demo 6");

  pinMode(enableMot, OUTPUT);
  pinMode(endStp, INPUT); // endstop to init motor

  digitalWrite(enableMot, LOW);

  stepper.setAcceleration(maxAccelerationSpeed);
  stepper.setSpeed(10000);

  Serial.println("tout est okay");
  initMot();
  Serial.println("After init");

  delay(1000);
}

void initMot()
{
    stepper.setMaxSpeed(initSpeed);
    stepper.moveTo(-30000);
    while(endStpState == HIGH)
    {
      endStpState = digitalRead(endStp);
      stepper.run();
    }
    stepper.stop();
    stepper.setCurrentPosition(-minSfyZone);
    stepper.setMaxSpeed(maxSpeed);

    delay(1000);
    stepper.moveTo(railLength-minSfyZone); //-minSfyZone-maxSfyZone);
    while (stepper.currentPosition() != railLength-minSfyZone)
      stepper.run();

    delay(1000);
    stepper.moveTo(0); //-minSfyZone-maxSfyZone);
    while (stepper.currentPosition() != 0)
      stepper.run();

    delay(1000);
    stepper.moveTo(playablePos); //-minSfyZone-maxSfyZone);
    while (stepper.currentPosition() != playablePos)
      stepper.run();

    delay(1000);
    stepper.moveTo(playablePos/2); //-minSfyZone-maxSfyZone);
    while (stepper.currentPosition() != playablePos/2)
      stepper.run();
}

int updateEncoderWay(long newEncoder)
{
  int newEncoderWay;

  if (newEncoder > posEncoder) // si le sens est du moteur ver la poulie
    newEncoderWay = ASC;
  else if(newEncoder < posEncoder) //si le sens est de la poulie
    newEncoderWay = DESC;
  else
    newEncoderWay = SAME;

  return (newEncoderWay);
}

int pos = 1000;

void loop()
{
  /*Serial.println("loop");
  stepper.setMaxSpeed(maxSpeed);
  stepper.moveTo(pos);
  if (stepper.currentPosition() >= pos)
    pos = 0;
  else if (stepper.currentPosition() < pos)
    pos = -1000;
*/

/*
stepper.moveTo(pos);

  stepper.run();
}

*/


/*
  long newEncoder;
  int newEncoderWay;

  newEncoder = knobLeft.read();

  if (newEncoder != posEncoder) //si l'encodeur a bouger
  {

    if (newEncoder > posPaddleMax || newEncoder < 0) //si on sort des boudries pour eviter de faire forcer le mot
    {
      knobLeft.write(posEncoder); // on reinit la position de l'encodeur
    }
    else //si on est dans la zone jouable
    {

      newEncoderWay = updateEncoderWay(newEncoder);

      if (encoderWay != newEncoderWay)
        {
              stepper.setMaxSpeed(0);
              //stepper.setAcceleration(0);
              //stepper.setSpeed(10);
              stepper.stop();
              stepper.setMaxSpeed(maxSpeed);
              //stepper.setAcceleration(maxAccelerationSpeed);
              Serial.println("+-------------------------------------+");
              Serial.print("|------------------");
              Serial.print(newEncoderWay);
              Serial.println("-------------------|");

              Serial.print("new Encoder : ");
              Serial.println(newEncoder);

              newEncoder = stepper.currentPosition();

              Serial.print("current Pos: ");
              Serial.println(newEncoder);

              knobLeft.write(newEncoder);
              encoderWay = newEncoderWay;
        }
          posEncoder = newEncoder;
          posPaddle = newEncoder;
    }

    if (posPaddle <= (posPaddleMax) && posPaddle >= 0)
    {
      stepper.moveTo(posPaddle);
    }


 }
    stepper.run();

}
*/

}
