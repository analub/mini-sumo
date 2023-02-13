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
    if(this->started == false){
      this->started = true;
      this->start_time_ms = millis();
    }

    if(this->finished == false){
    left_motor.setPower(this->left_motor_power);
    right_motor.setPower(this->right_motor_power);
    }

    //termina quando chegar no tempo determinado
    if((millis() - this->start_time_ms) >= this->time_ms){
      left_motor.setPower(0);
      right_motor.setPower(0);
      this->finished = true;      
    }
  return this->finished;
  }

  //InitialStrategy




  //AutoStrategy

  void AutoStrategy :: updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor){
  this->left_motor_power = 0;
  this->right_motor_power = 0;
    
  //criar condições para cada posição do inimigo

  switch(vision.enemy_position){
    case    EnemyPosition::FRONT:
            left_motor.setPower(100);
            right_motor.setPower(100);
            break;
          
    case    EnemyPosition::FULL_LEFT:
            left_motor.setPower(20);
            right_motor.setPower(90);
            break;

    case    EnemyPosition::FULL_RIGHT:
            left_motor.setPower(90);
            right_motor.setPower(20);
            break;
    
    case    EnemyPosition::LEFT:
            left_motor.setPower(30);
            right_motor.setPower(90);
            break;
              
    case    EnemyPosition::RIGHT:
            left_motor.setPower(90);
            right_motor.setPower(30);
            break;
  }

  
    