#include "esp32-hal-ledc.h"   //tự xuất hiện
#include "Servo.h"

void SERVO::InitSERVO(void){
  ledcSetup(servoChannel, servoFrequency, servoResolution);
  ledcAttachPin(servoPin, servoChannel);
}

void SERVO::StartSERVO(int Mode){
  if(Mode == 1)
    ServoMode1();
  else if(Mode == 2)
    ServoMode2();
}

void SERVO::ServoMode1(void){
  unsigned long currentMillis = millis();
  if (currentMillis - preMillis_servo >= Interval1){
      preMillis_servo = currentMillis;
      if (n == 0){
          ledcWrite(servoChannel, 3277);
          n = 1;
          Rotated = true;
      }
      else{
          ledcWrite(servoChannel, 6554);
          n = 0;
          Rotated = false;
      }
  }
}

void SERVO::ServoMode2(void){
  unsigned long currentMillis = millis();
  if (currentMillis - preMillis_servo >= Interval2){
      preMillis_servo = currentMillis;
      if (n == 0){
          ledcWrite(servoChannel, 3277);
          n = 1;
          Rotated = true;
      }
      else{
          ledcWrite(servoChannel, 6554);
          n = 0;
          Rotated = false;
      }
  }
}
