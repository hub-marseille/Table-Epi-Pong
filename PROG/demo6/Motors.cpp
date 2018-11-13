/*
 Guigur(.com) 2018
 guigur13@gmail.com
*/

#include "headers/Motors.hpp"

Motors::Motors(int step, int dir, int endStp, Motors::t_motorsInfos infos, Motors::t_paddleParams params)
{
  _step = step;
  _dir = dir;
  _endStp = endStp;
  _infos = infos;
  _params = params;
  _playablePos = params.railLength-params.minSfyZone-params.maxSfyZone;
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
      _stepper.moveTo(_targets.front().pos);

      Serial.print("Homing ");Serial.println(_infos.name);
      while(_endStpState == HIGH)
      {
        _endStpState = digitalRead(_endStp);
        _stepper.run();
      }
      _stepper.stop();
      _stepper.setCurrentPosition(-_params.minSfyZone);
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
    Serial.print("GOTO DONE: ");Serial.println(_targets.front().pos);
      _targets.erase(_targets.begin());
    }
  }
}

void Motors::initMotor()
{
  Serial.println("objet stepper init");
  this->GoTo(-30000, 0, false, true); //Homing

  this->GoTo(_params.railLength-_params.minSfyZone, 0, false, false, true);
  this->GoTo(0);
  this->GoTo(_playablePos);
  this->GoTo(_playablePos/2);
}

void Motors::GoTo(int newTarget, int delay, bool isInterupt, bool isHoming, bool force)
{
  if ((newTarget >= 0 && newTarget <= _playablePos) || force == true || (isHoming == true && newTarget < 0))
  {
    if (isInterupt == true)
        _targets.clear();
    _targets.push_back({newTarget, isHoming, delay});
  }
  else
  {
    Serial.print("GoTo : ");Serial.print(newTarget);Serial.print(" on motor ");Serial.print(_infos.name);Serial.println(" is forbiden");
  }
}
