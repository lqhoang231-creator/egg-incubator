#ifndef _DHT22_h
#define _DHT22_h

#include <DHT.h>
#define dhtPin 4
#define DHTTYPE DHT22

class DHT2x{
  private:                    
    DHT dht{dhtPin, DHTTYPE};
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