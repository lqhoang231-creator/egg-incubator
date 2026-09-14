#include "esp32-hal-gpio.h"
#include "Relay.h"
void RELAY::InitRELAY(void){
  pinMode(relayPin, OUTPUT);
}

void RELAY::OnRELAY(void){
  digitalWrite(relayPin, LOW);
}

void RELAY::OffRELAY(void){
  digitalWrite(relayPin, HIGH);
}