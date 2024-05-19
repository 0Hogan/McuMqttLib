#ifndef MQTT_MESSAGE_H
#define MQTT_MESSAGE_H

#include <cstdint>
#include <Arduino.h>
#include <ArduinoJson.h>

namespace Mqtt
{
  class Message
  {
    public:
      Message() {};

      const String getTopic() { return m_topic; }
      const char* getPayload() const;

    protected:
      void setTopic(String topic) { m_topic = topic; }
      virtual JsonDocument convertMsgToJson() const = 0;

    private:
      String m_topic = "";

  };
}

#endif // MQTT_MESSAGE_H
