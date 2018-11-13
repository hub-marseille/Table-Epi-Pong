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
  typedef struct   s_paddleParams
  {
    int            minSfyZone;
    int            maxSfyZone;
    int            railLength;
  } t_paddleParams;

  typedef struct   s_motorsInfos
  {
    String         name; //Name of the motor/axis
    t_paddleParams params;

  } t_motorsInfos;

  Motors(int step, int dir, int endStp, Motors::t_motorsInfos infos);
  ~Motors();
  void initMotor();
  void updateMotor();
  void GoTo(int newTarget, int delay = 0, bool isInterupt = false, bool isHoming = false, bool force = false);
private:
  int _step;
  int _dir;
  int _endStp;
  AccelStepper _stepper;
  int _minSfyZone;
  int _maxSfyZone;
  int _railLength;
  int _playablePos;
  t_motorsInfos _infos;

  typedef struct  s_targets
  {
    int           pos; //Absolute pos
    bool          homing; //Set this to true to home the motor, the pos will be ignored
    int           delay; //Delay after cmd
  } t_tagets;

  std::vector<t_tagets> _targets;
  int _endStpState = HIGH;
};

#endif /* MOTORS_HPP_ */
