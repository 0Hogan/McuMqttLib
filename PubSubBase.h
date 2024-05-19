#ifndef MQTT_PUB_SUB_BASE_H
#define MQTT_PUB_SUB_BASE_H

#include <cstdint>

#include <Adafruit_MQTT_Client.h>

namespace Mqtt
{
    class PubSubBase
    {
    protected:
        /**
         * @brief Construct a new PubSubBase object
         * 
         * @param client The connection to the client responsible for
         *               forwarding published messages to subscribers.
         */
        PubSubBase(Adafruit_MQTT_Client* client) : m_client(client) {}
        bool connectToClient();

        Adafruit_MQTT_Client* m_client = nullptr; ///< The connection to the client responsible for relaying messages from publishers to all subscribers.
    };
}

#endif // MQTT_PUB_SUB_BASE_H