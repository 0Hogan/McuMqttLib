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
      /**
       * @brief Construct a new Message object
       * 
       */
      Message() {};

      /**
       * @brief Get the message topic name.
       * 
       * @return const String 
       */
      const String getTopic() { return m_topic; }

      const char* getPayload() const;

    protected:
      /**
       * @brief Set the topic
       * 
       * @param topic The topic name preceded by any namespacing (e.g. "/iotDevices/livingRoom/lights/command")
       */
      void setTopic(String topic) { m_topic = topic; }

      /**
       * @brief Converts the message to a JSON representation.
       * 
       * @note This is a virtual function, so it shouldn't
       *       actually be used directly. The message class is 
       *       intended to be a parent class of the actual 
       *       messages.
       * 
       * @return JsonDocument A JSON representation of the
       *         contents of the Message instance. 
       */
      virtual JsonDocument convertMsgToJson() const = 0;

    private:
      String m_topic = "";

  };
}

#endif // MQTT_MESSAGE_H
