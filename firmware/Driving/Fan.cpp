#include "esp32-hal-ledc.h"
#include "esp32-hal-gpio.h"
#include "Fan.h"
#include <Arduino.h>

void FAN::InitFAN(void){
  pinMode(Pin_ain1, OUTPUT);
  pinMode(Pin_ain2, OUTPUT);
  pinMode(Pin_pwma, OUTPUT);
  pinMode(Pin_stby, OUTPUT);
  digitalWrite(Pin_stby, HIGH);
  ledcSetup(motorChannel, motorFrequency, motorResolution);
  ledcAttachPin(Pin_pwma, motorChannel);
  StartFAN(150);
}

void FAN::StartFAN(int Speed){
  Speed = constrain(Speed, 0, 255);     //constrain la gi? de lam gi?
  digitalWrite(Pin_ain1, HIGH);
  digitalWrite(Pin_ain2, LOW);
  ledcWrite(motorChannel, Speed);
}

void FAN::ControlFAN(void){
  unsigned long Interval = (motorRunning) ? runTime:stopTime;
  unsigned long Millis = millis();
  if(Millis - preMillis_motor >= Interval){
    preMillis_motor = Millis;
    motorRunning = !motorRunning;
    StartFAN(motorRunning ? 150:0);
  }
}