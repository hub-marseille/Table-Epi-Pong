#include <AccelStepper.h>

AccelStepper stepper(1, 3, 4);

const int enableMot = 8;
const int endStp = 2;

const int initSpeed = 150;

int posPaddle;
int posPaddleMinGame = 100;
int posPaddleMaxGame = 100;
int posPaddleMax = 1000;


int endStpState = HIGH;

void setup()
{
      Serial.begin(115200);
      while (!Serial) {;}
      pinMode(enableMot, OUTPUT);
      digitalWrite(enableMot, LOW);

      pinMode(endStp, INPUT); // enstop to init motor

      stepper.setAcceleration(2000);
      stepper.setSpeed(1000);

      initMot();
      delay(1000);
      stepper.setMaxSpeed(6000);
      stepper
      stepper.moveTo(posPaddleMaxGame);
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
}


void loop()
{
    if (stepper.distanceToGo() == 0)
    {
      if (posPaddle <= (posPaddleMax - posPaddleMaxGame) && posPaddle >= posPaddleMinGame)
      {
        Serial.println(posPaddle);
        stepper.moveTo(posPaddle);
      }
    }
    stepper.run();
}
