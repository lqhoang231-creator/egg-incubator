#include "HardwareSerial.h"   //tự xuất hiện
#include "DHT22.h"

void DHT2x::InitDHT22(void){
  dht.begin();
}

void DHT2x::ReadDHT22(void){
  unsigned long Millis = millis();
  if(Millis - preMillis_dht22 >= readTime){
    preMillis_dht22 = Millis;
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    if(isnan(temp)||isnan(hum)){
      temp = -1;
      hum = -1;
    }
    Serial.println("Temp: %f", temp);
    Serial.println("Hum: %f", hum);
  }
}