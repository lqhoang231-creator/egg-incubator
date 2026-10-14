#ifndef _Relay_h
#define _Relay_h

#define relayPin 27

class RELAY{
  private:
    unsigned long preMillis_relay = 0;
  public:
    void InitRELAY(void);
    void OnRELAY(int timeOn);
    void OffRELAY(void);
};

#endif