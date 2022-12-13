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
    
    if(ustart.state == 1)     //start 
      this-> robot_state = RobotState :: INITIAL_STRATEGY;
    else // parar
      this-> robot_state = RobotState :: STOPPED;
  }
