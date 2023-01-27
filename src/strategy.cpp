#include <iostream>
#include "../inc/strategy.h"
#include <Arduino.h>

using namespace std;

  Move :: Move(int left_motor_power, int right_motor_power, int time_ms){
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms;
  }

  bool Move :: update(MotorControl &left_motor, MotorControl &right_motor){
    if(left_motor.power>0 || right_motor.power>0)
      return 0;
    else return 1;
  }



  
