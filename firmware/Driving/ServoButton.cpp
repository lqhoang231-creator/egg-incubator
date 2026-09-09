#include "esp32-hal-gpio.h"
#include "ServoButton.h"

void BUTTON::InitBUTTON(void){
  pinMode(buttonPin, INPUT_PULLUP);
}

void BUTTON::ClickBUTTON(void){
  unsigned long Millies = millis();
  int Read = digitalRead(buttonPin);
  if(Read != lastButtonState){
    preMillis_button = Millies;
  }
  if(Millies - preMillis_button >= debounceTime){
      if(Read != buttonState){
        buttonState = Read;
        if(buttonState == LOW){
          Mode = (Mode == 1) ? 2:1;
        }
      }
    }
  lastButtonState = Read;
}