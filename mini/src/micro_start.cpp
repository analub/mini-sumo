#include <iostream>
#include "micro_start.h"

using namespace std;

  //iniciar em stop
  uStart :: uStart(int signal_pin){            
    this-> signal_pin = signal_pin;
    this->state = uStartState :: STOP;
  }

  //stop 0 e start 1
  void uStart :: update(){
    bool estado = digitalRead(this->signal_pin);     //lê para ver se muda estado
    if (estado == 1)
      this-> state = uStartState :: START;
    else
      this-> state = uStartState :: STOP;
  }
