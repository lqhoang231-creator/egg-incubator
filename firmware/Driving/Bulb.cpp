#include "esp32-hal-ledc.h"
#include "esp32-hal-gpio.h"
#include "Bulb.h"

void BULB::InitBULB(void){
  ledcSetup(bulbChannel, bulbFrequency, bulbResolution);
  ledcAttachPin(bulbPin, bulbChannel);
}

void BULB::ControlBULB(int bright){
  ledcWrite(bulbPin, bright);
}