#include <iostream>
#include "../inc/strategy.h"
#include <Arduino.h>

using namespace std;

  Move :: Move(int left_motor_power, int right_motor_power, int time_ms){
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms;
    this->start_time_ms = 0;
    this->finished = false;
    this->started = false;
  }

  bool Move :: update(MotorControl &left_motor, MotorControl &right_motor){
    //inicia movimento 
    this->started = true;
    this->start_time_ms = millis();

    left_motor.setPower(this->left_motor_power);
    right_motor.setPower(this->right_motor_power);

    //termina quando chegar no tempo determinado
    if(millis() - this->start_time_ms >= this->time_ms){
      left_motor.setPower(0);
      right_motor.setPower(0);
      this->finished = true;      
    }
    return finished;
  }
    