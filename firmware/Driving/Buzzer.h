#ifndef _Buzzer_h
#define _Buzzer_h

#define buzzerPin 19

class BUZZER{
  private:
    unsigned long preMillis_buzzer = 0;
    int warning_duration = 5000;
  public:
    void InitBUZZER(void);
    void OnBUZZER(void);
    void OffBUZZER(void);
};

#endif