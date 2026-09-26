#include "esp32-hal.h"
#include "esp32-hal-gpio.h"
#include "Buzzer.h"
#include <Arduino.h>

void BUZZER::InitBUZZER(void){
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void BUZZER::OnBUZZER(void){
  digitalWrite(buzzerPin, HIGH);
  unsigned long Millis = millis();
  if(Millis - preMillis_buzzer >= warning_duration){
    preMillis_buzzer = Millis;
    OffBUZZER();
  }
}

void BUZZER::OffBUZZER(void){
  digitalWrite(buzzerPin, LOW);
}