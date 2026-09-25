#ifndef _LimitSwitch_h
#define _LimitSwitch_h

#define switchPin 33

class SWITCH{
  public:
    void InitSWITCH(void);
    void ReadSWITCH(void);
  public:
    int Read;
};

#endif