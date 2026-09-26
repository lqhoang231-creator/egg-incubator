//----------Nhiệt độ & độ ẩm để ấp trứng gà: 37,5-37,8 day 1-18:50%-55% day 19-21:65%-75%----------//


#ifndef _DHT22_h
#define _DHT22_h

#include <DHT.h>
#define dhtPin 4
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