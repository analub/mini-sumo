#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "micro_start.h"
#include "digital_sensor.h"
#include "analog_sensor.h"
#include "motor_control.h"
#include "vision.h"
#include "strategy.h"

using namespace std;

#define FRONT_SENSOR_PIN 24
#define FULL_LEFT_SENSOR_PIN 28
#define FULL_RIGHT_SENSOR_PIN 23
#define LEFT_SENSOR_PIN 20
#define RIGHT_SENSOR_PIN 19

#define RIGHT_MOTOR_PWM_PIN 11
#define RIGHT_MOTOR_IN1_PIN 9
#define RIGHT_MOTOR_IN2_PIN 10
#define RIGHT_MOTOR_SPEED_CONST 1.0

#define LEFT_MOTOR_PWM_PIN 5
#define LEFT_MOTOR_IN1_PIN 7
#define LEFT_MOTOR_IN2_PIN 6
#define LEFT_MOTOR_SPEED_CONST 1.0

#define MICRO_START_SIGNAL_PIN 4

#define STRATEGY_PIN_A 14
#define STRATEGY_PIN_B 15
#define STRATEGY_PIN_C 13

namespace RobotState
{
  enum States
  {
    AWAITING_START,
    INITIAL_STRATEGY,
    AUTO_STRATEGY,
    STOPPED
  };
}

class Robot
{
public:
  string name = "robot";
  int led_pin = 13;
  RobotState::States robot_state; //atualizar estado do robô
  uStart ustart;   //microstart
  DigitalSensor front_sensor;
  DigitalSensor full_left_sensor;
  DigitalSensor full_right_sensor;
  AnalogSensor left_sensor;
  AnalogSensor right_sensor;
  MotorControl left_motor;
  MotorControl right_motor;
  Vision vision;
  InitialStrategy *initial_strategy;  //nao precisa
  AutoStrategy auto_strategy;

  void readSensors();
  void update();

  Robot();
};

#endif