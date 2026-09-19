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

int Switch_warningTime = 5000;
unsigned long Switch_preMillis = 0;

int DHT22_warningTime = 5000;
unsigned long DHT22_preMillis = 0;

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

//----------servo monitoring
  if(_button.Mode == 1){
    if(_switch.Read == LOW){
      unsigned long Millis = millis();
      if((Millis - Switch_preMillis >= (_servo.Interval1 + Switch_warningTime)) && (_switch.Read == LOW)){
        Switch_preMillis = Millis;
        _buzzer.OnBUZZER();
      }
    }
    if(_switch.Read == HIGH){
      unsigned long Millis = millis();
      if((Millis - Switch_preMillis >= (_servo.Interval1 + Switch_warningTime)) && (_switch.Read == HIGH)){
        Switch_preMillis = Millis;
        _buzzer.OnBUZZER();
      }
    }
  }
  if(_button.Mode == 2){
    if(_switch.Read == LOW){
      unsigned long Millis = millis();
      if((Millis - Switch_preMillis >= (_servo.Interval2 + Switch_warningTime)) && (_switch.Read == LOW)){
        Switch_preMillis = Millis;
        _buzzer.OnBUZZER();
      }
    }
    if(_switch.Read == HIGH){
      unsigned long Millis = millis();
      if((Millis - Switch_preMillis >= (_servo.Interval2 + Switch_warningTime)) && (_switch.Read == HIGH)){
        Switch_preMillis = Millis;
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