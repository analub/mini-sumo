#include <iostream>
#include <Arduino.h>
#include "../inc/analog_sensor.h"
using namespace std;

AnalogSensor :: AnalogSensor(int pin){    //construtor
  this-> pin = pin;
};

//leitura do sensor
int AnalogSensor :: readSensor(){
  this-> raw_reading = analogRead(this->pin);
  int auxReading = 4095 - this->raw_reading;
  this->distance_cm = (int)(auxReading * ANALOG_TO_CM);    //conversão do analogico pra cm
  return this-> distance_cm;
}
  
