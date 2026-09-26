#include "esp32-hal-gpio.h"
#include "Relay.h"
#include <Arduino.h>

void RELAY::InitRELAY(void){
  pinMode(relayPin, OUTPUT);
}

void RELAY::OnRELAY(int timeOn){
  digitalWrite(relayPin, LOW);
  unsigned long Millis = millis();
  if(Millis - preMillis_relay >= timeOn){
    preMillis_relay = Millis;
    OffRELAY();
  }
}

void RELAY::OffRELAY(void){
  digitalWrite(relayPin, HIGH);
}