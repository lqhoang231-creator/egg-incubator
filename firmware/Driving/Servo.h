#ifndef _Servo_h
#define _Servo_h

#define servoPin 13
#define servoChannel 0
#define servoFrequency 50
#define servoResolution 16

class SERVO{
  private:
    unsigned long preMillis_servo = 0;
    int n = 0;
  public:
    void InitSERVO(void);
    void StartSERVO(int Mode);
    void ServoMode1(void);
    void ServoMode2(void);
  public:
    unsigned long Interval1 = 20000;
    unsigned long Interval2 = 15000;
    bool Rotated = true;
};

#endif