#include "esp32-hal.h"
#include "esp32-hal-gpio.h"
#include "LimitSwitch.h"

void SWITCH::InitSWITCH(void){
  pinMode(switchPin, INPUT_PULLUP);
}

void SWITCH::ReadSWITCH(void){
  Read = digitalRead(switchPin);
}