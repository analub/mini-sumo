#include <iostream>
#include "digital_sensor.h"

using namespace std;

  DigitalSensor :: DigitalSensor(int pin){        //construtor
    this-> pin = pin;
  };

  int DigitalSensor :: readSensor(){          //leitura do sensor, inimigo perto
    this -> raw_reading = digitalRead(this->pin);
    
    if(this-> raw_reading <2000)
      this->enemy_close = true;
    else 
      this->enemy_close = false;
    
    if (enemy_close == 1)    
      return true;
    else
      return false;   
  }

  /*
  int DigitalSensor :: filterSensor(){}
    não precisa implementar
  */
