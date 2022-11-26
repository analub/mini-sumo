#include <iostream>
#include "vision.h"
using namespace std;

  void updateEnemyPosition (DigitalSensor &front_sensor, DigitalSensor &full_left_sensor, 
  DigitalSensor &full_right_sensor, AnalogSensor &left_sensor, AnalogSensor &right_sensor){
    
    //digital
    if(front_sensor.enemy_close){
      this-> enemy_position = EnemyPosition :: FRONT;
      return;
    }
    if(full_left_sensor.enemy_close){
      this-> enemy_position = EnemyPosition :: FULL_LEFT;
      return;
    }
    if(full_right_sensor.enemy_close){
      this-> enemy_position = EnemyPosition :: FULL_RIGHT;
      return;
    }
    
    //analogico
    if(left_sensor.distance_cm <=20 && right_sensor.distance_cm <=20){
      this -> enemy_position = EnemyPosition :: FRONT;
      return;
    }
    if(left_sensor.distance_cm <=20 && right_sensor.distance_cm >20){
      this-> enemy_position = EnemyPosition :: LEFT;
      this-> latest_enemy_position = EnemyPosition :: LEFT;
      return;
    }
    if(left_sensor.distance_cm >20 && right_sensor.distance_cm <=20){
      this-> enemy_position = EnemyPosition :: RIGHT;
      this-> latest_enemy_position = EnemyPosition :: RIGHT;
      return;
    }

  //procurar baseado na ultima posição passada
    if(latest_enemy_position = Enemy_position :: LEFT;){
      enemy_position = EnemyPosition :: SEARCH_LEFT;
      return;
    }
    if(latest_enemy_position == EnemyPosition :: RIGHT;){
      enemy_position = EnemyPosition :: SEARCH_RIGHT;
      return;
    }
  }