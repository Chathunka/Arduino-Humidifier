/*
  Humidifier.cpp - Library for generating ultrahigh frequencies 
  for liquid atomization using AVR microcontrollers.
  Created by Chathunka J. Tennakoon, November 2, 2020.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Humidifier.h"

Humidifier::Humidifier(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  //Timer1
  TCCR1A = _BV(COM1A1)|_BV(WGM11);
  TCCR1B = _BV(CS10) |_BV(WGM13) |_BV(WGM12);// no prescaling but /2 phase and frequency correct
  ICR1   = 0;//100 to get 158 Khz - 138 to get 116 Khz
  OCR1A = 0;
}

void Humidifier::setWave(int freq , int duty)
{
	if(freq > 150){
		ICR1 = 138; //100 to get 158 Khz - 138 to get 116 Khz
		if(_pin == 9) OCR1A = int(ICR1 * duty / 100);
		else OCR1B = int(ICR1 * duty / 100);
	}else{
		ICR1 = 100; //100 to get 158 Khz - 138 to get 116 Khz
		if(_pin == 9) OCR1A = int(ICR1 * duty / 100);
		else OCR1B = int(ICR1 * duty / 100);
	}
}

