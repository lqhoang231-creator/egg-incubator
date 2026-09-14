#include "esp32-hal-gpio.h"
#include "Buzzer.h"

void BUZZER::InitBUZZER(void){
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void BUZZER::OnBUZZER(void){
  digitalWrite(buzzerPin, HIGH);
}

void BUZZER::OffBUZZER(void){
  digitalWrite(buzzerPin, LOW);
}