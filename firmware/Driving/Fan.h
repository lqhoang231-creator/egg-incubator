#ifndef _Fan_h
#define _Fan_h

#define Pin_ain1 17
#define Pin_ain2 5
#define Pin_pwma 18
#define Pin_stby 16
#define motorChannel 4

class FAN{
  private:
    unsigned long preMillis_motor = 0;
    int runTime = 5000;
    int stopTime = 10000;
    bool motorRunning = true;
    int motorFrequency = 1000;
    int motorResolution = 8;
    //int Speed = 150;
  public:
    void InitFAN(void);
    void StartFAN(int Speed);
    void ControlFAN(void);
};

#endif