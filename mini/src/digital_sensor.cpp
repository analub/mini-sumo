#include <iostream>
#include "../inc/digital_sensor.h"
#include <Arduino.h>

using namespace std;

  DigitalSensor :: DigitalSensor(int pin)
  {
    this-> pin = pin;
  };

  int DigitalSensor :: readSensor(){                //leitura do sensor, inimigo perto
    this -> raw_reading = digitalRead(this->pin);
    
    if(this-> raw_reading==1)
      this->enemy_close = true;
    else 
      this->enemy_close = false;
    
    if (this->enemy_close == 1)    
      return this->enemy_close;
    else
      return 0;   
  }

  /*
  int DigitalSensor :: filterSensor(){}
    não precisa implementar
  */
