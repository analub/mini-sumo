#include <iostream>
#include "../inc/strategy.h"
#include <Arduino.h>

using namespace std;

  Move :: Move(int left_motor_power, int right_motor_power, int time_ms){
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms;
  }



  
