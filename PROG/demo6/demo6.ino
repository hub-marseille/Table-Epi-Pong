#include <AccelStepper.h>
#include <Encoder.h>

AccelStepper stepper(AccelStepper::DRIVER, 3, 4);
Encoder knobLeft(0, 1);

const int enableMot = 8;
const int endStp = 2;

const int initSpeed = 150;
const int maxSpeed = 6000;
const int maxAccelerationSpeed = 2000;

int posPaddle;
int posPaddleMinGame = 100;
int posPaddleMaxGame = 100;
int posPaddleMax = 2700;

long posEncoder;

int endStpState = HIGH;

enum way {ASC, DESC, SAME};
int encoderWay = SAME;

void setup()
{
      Serial.begin(115200);
      //while (!Serial) {;}
      pinMode(enableMot, OUTPUT);
      digitalWrite(enableMot, LOW);

      pinMode(endStp, INPUT); // enstop to init motor

      stepper.setAcceleration(maxAccelerationSpeed);
      stepper.setSpeed(1000);
      //stepper.direction(DIRECTION_CW);


      initMot();

      delay(1000);
      stepper.setMaxSpeed(maxSpeed);

      //knobLeft.write(posPaddleMax/2);
      //stepper.moveTo(posPaddleMax/2);
      delay(5000);
}

void initMot()
{
    stepper.setMaxSpeed(initSpeed);
    stepper.moveTo(3000);
    while(endStpState == HIGH)
    {
      endStpState = digitalRead(endStp);
      stepper.run();
    }
    stepper.stop();
    stepper.setCurrentPosition(posPaddleMax);
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


void loop()
{
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
