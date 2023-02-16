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

  InitialStrategy :: InitialStrategy(std :: list<Move> moves) : current_move(moves.front()){
    this->strategy_finished = false;
    this->moves = moves;
  }

  bool InitialStrategy :: update(MotorControl &left_motor, MotorControl&right_motor){
    this->current_move.update(left_motor, right_motor);
    
    if(current_move.update(left_motor, right_motor) == true){
      //primeiro movimento sai e passa para próximo
      moves.pop_front();
      this->current_move = moves.front();
    }

    //verifica se lista está fazia pra finalizar estratégia
    if(moves.empty())
      this->strategy_finished = true;
  }

  InitialStrategy* get_selected_strategy(int pinA, int pinB, int pinC){
    std :: list<Move> moves;
    int option = pinA + (2*pinB) + (4*pinC);      //pinA: menos significativo

    switch(option){
      case 0:
              //direita, frente, esquerda
              moves.push_back(Move(100,0,200));
              moves.push_back(Move(50,50,1000));
              moves.push_back(Move(0,100,400));
              break;

      case 1:
              //esquerda, frente, direita
              moves.push_back(Move(0,100,200));
              moves.push_back(Move(50,50,1000));
              moves.push_back(Move(100,0,400));
              break;

      case 2:
              //direita, frente, esquerda, frente
              moves.push_back(Move(100,0,200));
              moves.push_back(Move(90,90,1000));
              moves.push_back(Move(0,100,200));
              moves.push_back(Move(90,90,1000));
              break;

      case 3: 
              //esquerda, frente, direita, frente
              moves.push_back(Move(0,100,200));
              moves.push_back(Move(90,90,1000));
              moves.push_back(Move(100,0,200));
              moves.push_back(Move(90,90,1000));
              break;
      case 4:
              //frente, frente, esquerda, frente, direita
              moves.push_back(Move(90,90,2000));
              moves.push_back(Move(0,100,200));
              moves.push_back(Move(90,90,1000));
              moves.push_back(Move(100,0,200));
              break;
        
      case 5: 
              //frente, frente, direita, frente, esquerda
              moves.push_back(Move(90,90,2000));
              moves.push_back(Move(100,0,200));
              moves.push_back(Move(90,90,1000));
              moves.push_back(Move(0,100,200));
              break;
      
      case 6: 
              //frente
              moves.push_back(Move(100,100,1000));
              break;
      
      case 7:  
              //esquerda, esquerda, frente - virar
              moves.push_back(Move(0,100,2000));
              moves.push_back(Move(100,100,1000));
              break;
    } 
  }

  //AutoStrategy

  void AutoStrategy :: updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor){
  this->left_motor_power = 0;
  this->right_motor_power = 0;

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
  }

  
    