#ifndef _DHT22_h
#define _DHT22_h

#include <DHT.h>
#define dataPin 4
#define DHTTYPE DHT22

class DHT2x{
  private:                    //pri chia ra 1 cái ghi hàm, 1 cái ghi biến hay ghi chung luôn
    DHT dht(dhtPin, DHTTYPE);
  private:
    int preMillis_dht22 = 0;
    int readTime = 10000;
  public:
    float temp;
    float hum;
  public:
    void InitDHT22(void);
    void ReadDHT22(void);
};

#endif