#include "esp32-hal-gpio.h"
#include "Hall.h"

void HALL::InitHALL(void){
  pinMode(hallPin, INPUT_PULLUP);
}

void HALL::ReadHALL(void){
  Read_HALL = digitalRead(hallPin);
  return Read_HALL;
}