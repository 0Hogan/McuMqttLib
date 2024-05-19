#ifndef MQTT_PUB_SUB_BASE_H
#define MQTT_PUB_SUB_BASE_H

#include <cstdint>

#include <Adafruit_MQTT_Client.h>

namespace Mqtt
{
    class PubSubBase
    {
    protected:
        PubSubBase(Adafruit_MQTT_Client* client) : m_client(client) {}
        bool connectToClient();
        
        Adafruit_MQTT_Client* m_client = nullptr;
    };
}

#endif // MQTT_PUB_SUB_BASE_H