#ifndef _Bulb_h
#define _Bulb_h

#define bulbPin 7
#define bulbChannel 8
#define bulbFrequency 1000
#define bulbResolution 8

class BULB{
  public:
    void InitBULB(void);
    void ControlBULB(void);
};

#endif