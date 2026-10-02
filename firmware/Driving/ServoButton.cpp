#include "esp32-hal-gpio.h"
#include "ServoButton.h"
#include <Arduino.h>
#include "Buzzer.h"

BUZZER _buzzeroff;

void BUTTON::InitBUTTON(void){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
}

void BUTTON::ClickBUTTON(void){
  unsigned long Millis = millis();
  int Read = digitalRead(buttonPin);
  if(Read != lastButtonState){
    preMillis_button = Millis;
  }
  if(Millis - preMillis_button >= debounceTime){
      if(Read != buttonState){
        buttonState = Read;
        if(buttonState == LOW){
          Mode = (Mode == 1) ? 2:1;
        }
      }
    }
  lastButtonState = Read;
}

void BUTTON::Reset(void){
  unsigned long Millis_reset = millis();
  Read_resetbutton = digitalRead(resetButton);
  if(Read_resetbutton != ResetState){
    preReset = Millis_reset;
  }
  if(Millis_reset - preReset >= debounceTime){
    if(Read_resetbutton != ResetState)
      _buzzeroff.OffBUZZER();
  }
}