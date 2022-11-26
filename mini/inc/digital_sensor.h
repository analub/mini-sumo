#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

class DigitalSensor
{
public:
    int raw_reading;
    int filtered_reading;  //não precisa implementar
    bool enemy_close;
    int pin;
    int readSensor();
    int filterSensor();   //não precisa implementar
    DigitalSensor(int pin);
};

#endif