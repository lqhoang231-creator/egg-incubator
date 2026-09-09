#ifndef _ServoButton_h
#define _ServoButton_h

#define buttonPin 25

class BUTTON{
  private:
    int lastButtonState = HIGH;
    int buttonState = HIGH;
    int debounceTime = 50;
    unsigned long preMillis_button = 0;
  public:
    void InitBUTTON(void);
    void ClickBUTTON(void);
  public:
    int Mode = 1;       
};

#endif