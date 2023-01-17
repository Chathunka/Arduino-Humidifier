/*
  Humidifier.h - Library for generating ultrahigh frequencies 
  for liquid atomization using AVR microcontrollers.
  Created by Chathunka J. Tennakoon, November 2, 2020.
  Released into the public domain.
*/
#ifndef Humidifier_h
#define Humidifier_h

#include "Arduino.h"

class Humidifier
{
  public:
    Humidifier(int pin);
    void setWave(int freq , int duty);
  private:
    int _pin;
};

#endif