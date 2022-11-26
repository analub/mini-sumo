#include <iostream>
#include "analog_sensor.h"
using namespace std;

  AnalogSensor :: AnalogSensor(int pin){    //construtor
    this-> pin = pin;
  };

  //leitura do sensor
  int AnalogSensor :: readSensor(){
    this-> raw_reading = analogRead(this->pin);
    this->distance_cm = (int)(this->raw_reading * ANALOG_TO_CM);    //conversão do analogico pra cm
    return this-> distance_cm;
}
  
