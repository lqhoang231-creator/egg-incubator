#include "esp32-hal.h"
#include "OTA.h"
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>
#include <WiFiAP.h>

String OTA::GetMAC(void){
  String MAC;
  MAC = WiFi.macAddress();
  MAC.replace(":", "");

  Serial.println("");
  Serial.print("MAC: ");
  Serial.println(MAC);

  return MAC;
}

void OTA::InitOTA(void){
  WiFi.mode(WIFI_STA);
  WiFi.begin(Wifi_name, Wifi_password);
  Serial.println("Connecting to wifi...");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Khong ket noi duoc Wi-Fi!");
    return;
  }
  Serial.println("Da ket noi Wi-Fi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.setHostname(OTA_hostname);
  ArduinoOTA.setPassword(OTA_password);

  ArduinoOTA
    .onStart([]() {
      Serial.println("Bat dau cap nhat OTA...");
    })
    .onEnd([]() {
      Serial.println("\nCap nhat hoan tat!");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Tien do: %u%%\r", (progress * 100) / total);
    })
    .onError([](ota_error_t error) {
      Serial.printf("Loi OTA [%u]: ", error);

      if (error == OTA_AUTH_ERROR)
        Serial.println("Sai mat khau");
      else if (error == OTA_BEGIN_ERROR)
        Serial.println("Loi bat dau");
      else if (error == OTA_CONNECT_ERROR)
        Serial.println("Loi ket noi");
      else if (error == OTA_RECEIVE_ERROR)
        Serial.println("Loi nhan du lieu");
      else if (error == OTA_END_ERROR)
        Serial.println("Loi ket thuc");
    });
  ArduinoOTA.begin();
  Serial.println("OTA san sang!");
}

void OTA::HandleOTA(void){
  if (WiFi.status() == WL_CONNECTED){
    ArduinoOTA.handle();
  }
}

bool OTA::StatusOTA(void){
  return WiFi.status() == WL_CONNECTED;
}