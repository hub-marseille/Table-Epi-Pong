#include "headers/Motors.hpp"



Motors::Motors(int step, int dir, int endStp, int minSfyZone, int maxSfyZone, int railLength)
{
  Serial.println("objet stepper créer");
  _step = step;
  _dir = dir;
  _endStp = endStp;
  _minSfyZone = minSfyZone;
  _maxSfyZone = maxSfyZone;
  _railLength = railLength;
  _playablePos= railLength-minSfyZone-maxSfyZone;
  _stepper = AccelStepper(AccelStepper::DRIVER, _step, _dir);
}

Motors::~Motors()
{
  Serial.println("objet stepper detruit");
}

void Motors::updateMotor()
{
  if (!_targets.empty())
  {
    if (_stepper.currentPosition() != _targets.front())
    {
      _stepper.moveTo(_targets.front());
      _stepper.run();
    }
    else
    {
      Serial.println(_targets.front());
      _targets.erase(_targets.begin());
    }
  }
}

void Motors::initMotor()
{
  Serial.println("objet stepper init");

  _stepper.setAcceleration(MAXACCELERATIONSPEED);
  _stepper.setSpeed(10000);

  _stepper.setMaxSpeed(INITSPEED);
  _stepper.moveTo(-30000);
  _target = -30000;
  Serial.print("target1: ");
  Serial.println(_target);
  while(_endStpState == HIGH)
  {
    _endStpState = digitalRead(_endStp);
    _stepper.run();
  }
  _stepper.stop();
  _stepper.setCurrentPosition(-_minSfyZone);
  _stepper.setMaxSpeed(MAXSPEED);
  delay(1000);
  _targets.push_back(_railLength-_minSfyZone);
  _targets.push_back(0);
  _targets.push_back(_playablePos);
  _targets.push_back(_playablePos/2);
}

void Motors::GoTo(int newTarget, bool isInterupt)
{
  if (isInterupt == true)
      _targets.clear();
  _targets.push_back(newTarget);
Serial.println("GOTO");
}
