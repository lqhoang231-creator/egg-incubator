#include "Mainprogram.h"
#include "DHT22.h"
#include "Servo.h"
#include "ServoButton.h"
#include "Fan.h"

DHT2x _dht22;
SERVO _servo;
BUTTON _button;
FAN _fan;
BUZZER _buzzer;
HALL _hall;

void Init(void){
  _fan.InitFAN();
  _dht22.InitDHT22();
  _servo.InitSERVO();
  _button.InitBUTTON();
  _buzzer.InitBUZZER();
}

void Runmainprogram(void){
  _dht22.ReadDHT22();
  _button.ClickBUTTON();
  _servo.StartSERVO(_button.Mode);
  _fan.ControlFAN();
  if(_dht22.temp < 37 || _dht22.temp > 38){
    _buzzer.OnBUZZER();
  }
  else{
    _buzzer.OffBUZZER();
  }
}