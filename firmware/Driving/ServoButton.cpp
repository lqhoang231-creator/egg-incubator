#include "esp32-hal-gpio.h"
#include "ServoButton.h"

void BUTTON::InitBUTTON(void){
  pinMode(buttonPin, INPUT_PULLUP);
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