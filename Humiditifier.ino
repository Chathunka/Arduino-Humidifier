#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  delay(1000);
  
  //Timer1
  TCCR1A = _BV(COM1A1)|_BV(WGM11);
  TCCR1B = _BV(CS10) |_BV(WGM13) |_BV(WGM12);// no prescaling but /2 phase and frequency correct
  ICR1   = 0;//100 to get 158 Khz - 138 to get 158 Khz
  OCR1A = 0;
  TIMSK1 = _BV(TOIE1);
  
}

void loop() {
  digitalWrite(7,LOW);
  ICR1   = 138;//100 to get 158 Khz - 138 to get 158 Khz
  OCR1A = ICR1/2;
  digitalWrite(8,HIGH);
  delay(2000);
  digitalWrite(8,LOW);
  ICR1   = 100;//100 to get 158 Khz - 138 to get 158 Khz
  OCR1A = ICR1/2;
  digitalWrite(7,HIGH);
  delay(2000);
}

ISR(TIMER1_OVF_vect){
}
