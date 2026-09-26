#include <ArduinoOTA.h>
#include "esp32-hal.h"
#include "Mainprogram.h"
#include "DHT22.h"
#include "Servo.h"
#include "ServoButton.h"
#include "Fan.h"
#include "Buzzer.h"
#include "Hall.h"
#include "Relay.h"
#include "LimitSwitch.h"
#include "Bulb.h"
#include "OTA.h"
#include <Arduino.h>

DHT2x _dht22;
SERVO _servo;
BUTTON _button;
FAN _fan;
BUZZER _buzzer;
HALL _hall;
RELAY _relay;
SWITCH _switch;
BULB _bulb;
OTA _ota;

#define max_temp 38
#define min_temp 37
#define max_hum 55
#define min_hum 50
#define mist_duration 3000

int Switch_warningTime = 4000;
unsigned long Switch_preMillis = 0;

int DHT22_warningTime = 5000;
unsigned long DHT22_preMillis = 0;

unsigned long Hall_preMillis = 0;
int Hall_value = LOW;
int Fan_warningTime = 4000;

void Init(void){
  Serial.begin(115200);
  _fan.InitFAN();
  _dht22.InitDHT22();
  _servo.InitSERVO();
  _button.InitBUTTON();
  _buzzer.InitBUZZER();
  _hall.InitHALL();
  _relay.InitRELAY();
  _switch.InitSWITCH();
  _bulb.InitBULB();
  _ota.GetMAC();
  _ota.InitOTA();
}

void Runmainprogram(void){
  _ota.HandleOTA();
  unsigned long MainMillis = millis();
  _dht22.ReadDHT22();
  _button.ClickBUTTON();
  _servo.StartSERVO(_button.Mode);
  _fan.ControlFAN();
  _switch.ReadSWITCH();

//----------fan monitoring
  if(_hall.ReadHALL() != Hall_value){
    Hall_value = _hall.ReadHALL();
    Hall_preMillis = MainMillis;
  }
  if(MainMillis - Hall_preMillis >= Fan_warningTime){
    _buzzer.OnBUZZER();
  }

//----------servo monitoring
  if(_servo.Rotated == true){
    unsigned long Check_Millis = millis();
    if(Check_Millis - Switch_preMillis >= Switch_warningTime){
      Switch_preMillis = Check_Millis;
      if(_switch.Read == HIGH){
        _buzzer.OnBUZZER();
      }
    }
  }
  else{
    unsigned long Check_Millis = millis();
    if(Check_Millis - Switch_preMillis >= Switch_warningTime){
      Switch_preMillis = Check_Millis;
      if(_switch.Read == LOW){
        _buzzer.OnBUZZER();
      }
    }
  }

//----------temperature & humidity monitoring
  if(_dht22.temp < 37 || _dht22.temp > 38 || _dht22.hum < 50 || _dht22.hum > 55){
    if(MainMillis - DHT22_preMillis >= DHT22_warningTime){
      if(_dht22.temp < 37 || _dht22.temp > 38 || _dht22.hum < 50 || _dht22.hum > 55){
        DHT22_preMillis = MainMillis;
        _buzzer.OnBUZZER();
      }
    }

    if(_dht22.temp > max_temp)
      _bulb.ControlBULB(50);
    else if(_dht22.temp < min_temp){
      if(_dht22.temp == -1)
        _buzzer.OnBUZZER();
      _bulb.ControlBULB(175);
    }

    if(_dht22.hum > max_hum)
      _fan.StartFAN(230);
    else if(_dht22.hum < min_hum)
      _relay.OnRELAY(mist_duration);
  }

  else{
    _fan.StartFAN(180);
    _bulb.ControlBULB(100);
  }
}