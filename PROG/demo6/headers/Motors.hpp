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
  void GoTo(int newTarget, bool isInterupt = false, bool isHoming = false);
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

  typedef struct  s_targets
  {
    int           pos; //Absolute pos
    bool          isHoming; //Set this to true to home the motor, the pos will be ignored
    int           delay; //Delay after cmd
  } t_tagets;

  std::vector<t_tagets> _targets;
  int _endStpState = HIGH;
};

#endif /* MOTORS_HPP_ */
