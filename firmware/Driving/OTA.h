#ifndef _OTA_h
#define _OTA_h
#include <Arduino.h>

#define Wifi_name "Galaxya12"
#define Wifi_password "01234567890"

#define OTA_hostname "ESP32-Incubator"
#define OTA_password "231007"

class OTA{
  public:
    void InitOTA(void);
    void HandleOTA(void);
    bool StatusOTA(void);
    String GetMAC(void);
};

#endif