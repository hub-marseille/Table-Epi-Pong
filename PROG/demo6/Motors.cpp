/*
 Guigur(.com) 2018
 guigur13@gmail.com
*/

#include "headers/Motors.hpp"

Motors::Motors(int step, int dir, int endStp, int minSfyZone, int maxSfyZone, int railLength)
{
  _step = step;
  _dir = dir;
  _endStp = endStp;
  _minSfyZone = minSfyZone;
  _maxSfyZone = maxSfyZone;
  _railLength = railLength;
  _playablePos = railLength-minSfyZone-maxSfyZone;
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
    if (_targets.front().homing == true)
    {
      _stepper.setAcceleration(MAXACCELERATIONSPEED);
      _stepper.setSpeed(10000);
      _stepper.setMaxSpeed(INITSPEED);
      _stepper.moveTo(-30000);
      Serial.print("Homing");
      Serial.println(-30000);
      while(_endStpState == HIGH)
      {
        _endStpState = digitalRead(_endStp);
        _stepper.run();
      }
      _stepper.stop();
      _stepper.setCurrentPosition(-_minSfyZone);
      _stepper.setMaxSpeed(MAXSPEED);
      _targets.erase(_targets.begin());
    }
    else if (_stepper.currentPosition() != _targets.front().pos)
    {
      _stepper.moveTo(_targets.front().pos);
      _stepper.run();
    }
    else
    {
      Serial.println(_targets.front().pos);
      _targets.erase(_targets.begin());
    }
  }
}

void Motors::initMotor()
{
  Serial.println("objet stepper init");
  this->GoTo(0, 0, false, true); //Homing

  this->GoTo(_railLength-_minSfyZone);
  this->GoTo(0);
  this->GoTo(_playablePos);
  this->GoTo(_playablePos/2);
}

void Motors::GoTo(int newTarget, int delay, bool isInterupt, bool isHoming)
{
  if (isInterupt == true)
      _targets.clear();
  _targets.push_back({newTarget, isHoming, delay});
}
