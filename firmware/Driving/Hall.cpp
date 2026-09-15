#include "esp32-hal-gpio.h"
#include "Hall.h"

void HALL::InitHALL(void){
  pinMode(hallPin, INPUT);
}

void HALL::ReadHALL(void){
  digitalRead(hallPin);
}