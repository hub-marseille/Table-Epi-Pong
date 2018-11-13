#include <AccelStepper.h>
//#include <Encoder.h>
#include "headers/Motors.hpp"
#include <vector>
#include "headers/config.hpp"

//Encoder knobLeft(0, 1);

const int enableMot = 8;
Motors::t_paddleParams paddleParams = {500, 700, 11000};
Motors::t_paddleParams ballShortParams = {0, 0, 0};
Motors::t_paddleParams ballLongParams = {0, 0, 0};

Motors paddleMaster(3, 4, 2, {"paddle master", paddleParams});
Motors paddleSlave(24, 25, 31, {"paddle slave", paddleParams});

//int posPaddle;
//long posEncoder;
//enum way {ASC, DESC, SAME};
//int encoderWay = SAME;
bool   doOnce = true;

void setup()
{
  Serial.begin(115200);
  while (!Serial) {;}
  Serial.println("Demo 6");

  pinMode(enableMot, OUTPUT);
  digitalWrite(enableMot, LOW);
  pinMode(2, INPUT); // endstop to init motor
  pinMode(31, INPUT); // endstop to init motor


  //paddleMaster.initMotor();
  paddleMaster.initMotor();
  paddleSlave.initMotor();

  delay(1000);
}

void loop()
{
  paddleMaster.updateMotor();
  paddleSlave.updateMotor();

}

/*
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
*/

//int pos = 1000;


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
