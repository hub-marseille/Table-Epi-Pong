#ifndef MOTORS_HPP_
# define MOTORS_HPP_

#include <String.h>
#include <Arduino.h>
#include <vector>
#include <AccelStepper.h>
# include "config.hpp"
class Motors
{
public:
  Motors(int step, int dir, int endStp, int minSfyZone, int maxSfyZone, int railLength);
  ~Motors();
  void initMotor();
  void updateMotor();
  void GoTo(int newTarget, bool isInterupt);
private:
  int _step;
  int _dir;
  int _endStp;
  AccelStepper _stepper;
  int _minSfyZone;
  int _maxSfyZone;
  int _railLength;
  int _playablePos;
  bool _isInit = false;
  int _target = 0;
  std::vector<int> _targets;
  int _endStpState = HIGH;
};

#endif /* MOTORS_HPP_ */
