#include "motor_control.h"
#include <iostream>
#include <Arduino.h>

using namespace std;

  MotorConfig :: MotorConfig(int pwm_pin, int in1_pin, int in2_pin, float speed_const){
    this-> pwm_pin = pwm_pin;
    this->in1_pin = in1_pin;              
    this->in2_pin = in2_pin;
    this->speed_const = speed_const; 
  }

  MotorControl :: MotorControl (int pwm_pin, int in1_pin, int in2_pin, float speed_const){
    this-> pwm_pin = pwm_pin;
    this->in1_pin = in1_pin;              
    this->in2_pin = in2_pin;
    this->speed_const = speed_const; 
  }

  void MotorControl :: setPower(int power){
    this->power = power;
    
    //ajuste
    float fixed_power = power * this->config.speed_const;
    int pwm = (int)(this->max_power / (100.0) * 255.0 * ((float)abs(fixed_power) / 100.0);
    
    if (fixed_power >= -100 && fixed_power <0){
      digitalWrite(this->config.in1_pin, false);
      digitalWrite(this->config.in2_pin, true);
      }
    else if (fixed_power>=0 && fixed_power <= 100){
      digitalWrite(this->config.in1_pin, true);
      digitalWrite(this->config.in2_pin, false);
      }
    else{
      Serial.println("invalid power");
      return; 
        }
    }