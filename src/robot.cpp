#include <iostream>
#include "../inc/robot.h"
using namespace std;

  Robot :: Robot() : ustart(MICRO_START_SIGNAL_PIN),front_sensor(FRONT_SENSOR_PIN),full_left_sensor(FULL_LEFT_SENSOR_PIN), 
  full_right_sensor(FULL_RIGHT_SENSOR_PIN), left_sensor(LEFT_SENSOR_PIN), right_sensor(RIGHT_SENSOR_PIN), 
  left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST), 
  right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST), vision()
  {
    this-> robot_state = RobotState :: AWAITING_START; //começa esperando
  }
  
  void Robot :: readSensors(){
    //leitura de sensores
    this-> front_sensor.readSensor();
    this-> full_left_sensor.readSensor();
    this-> full_right_sensor.readSensor();
    this-> left_sensor.readSensor();
    this-> right_sensor.readSensor();
  }

  void Robot :: update(){
    ustart.update();
    vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, right_sensor);

    if(ustart.state == uStartState :: START){
      
      Move initial_move_1(100,0,200);
      initial_move_1.update(this->left_motor, this->right_motor);
      vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, right_sensor);

      if(initial_move_1.update(this->left_motor, this->right_motor) == true){
        Move initial_move_2(50,50,1000);
        initial_move_2.update(this->left_motor, this->right_motor);
        vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, right_sensor);

        if(initial_move_2.update(this->left_motor, this->right_motor) == true){
          Move initial_move_3(100,0,400);
          initial_move_3.update(this->left_motor, this->right_motor);
          vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, right_sensor);    
        }
      }
    }
  }