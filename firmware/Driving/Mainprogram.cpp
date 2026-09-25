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

int Switch_warningTime = 2000;
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
  if(_dht22.temp < 37 || _dht22.temp > 38 || _dht22.hum < 50 || _dht22 > 55){
    if(MainMillis - DHT22_preMillis >= DHT22_warningTime){
      DHT22_preMillis = MainMillis;
      _buzzer.OnBUZZER();
    }
    if(_dht22.temp > 38 || _dht22.hum > 55){
      _fan.StartFAN(240);
      _bulb.ControlBULB(50);
    }
    if(_dht22.temp < 37 || _dht22.hum < 55){
      _fan.StartFAN(60);
      _bulb.ControlBULB(175);
      _relay.OnRELAY(3000);
    }
  }
  else{
    _fan.StartFAN(150);
    _bulb.ControlBULB(100);
  }
}