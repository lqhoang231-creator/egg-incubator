#ifndef _mqtt_h
#define _mqtt_h

class MQTT{
  private:
    const char* MQTT_SERVER = "broker.hivemq.com";
    const int MQTT_PORT = 1883;
    const char* TOPIC_TEMPERATURE = "incubator/data/temperature";
    const char* TOPIC_HUMIDITY    = "incubator/data/humidity";
  public:
    void MqttSetup(void);
    void MqttLoop(void);
    void MqttPublishTemp(float temp);
    void MqttPublishHum(float hum);
    void MqttWarning();
    bool MqttIsConnected(void);

    void mqttCallback(char* topic, byte* payload, unsigned int length);
};

#endif