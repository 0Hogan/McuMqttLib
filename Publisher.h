#ifndef MQTT_PUBLISHER_H
#define MQTT_PUBLISHER_H

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "PubSubBase.h"

namespace Mqtt
{
    template<typename msgType>
    class Publisher : protected PubSubBase
    {
    public:
        /**
         * @brief Construct a new Publisher object
         * 
         * @param client The connection to the client to which the publisher sends messages.
         */
        Publisher(Adafruit_MQTT_Client* client) : PubSubBase(client)
        {
            msgType msg;
            m_publisher = new Adafruit_MQTT_Publish(client, msg.getTopic().c_str());
        }

        /**
         * @brief Publishes the given message to the appropriate MQTT topic.
         * 
         * @param msg The message to be published. msg must be derived from Mqtt::Message.
         */
        void publish(const msgType &msg) 
        {
            if (connectToClient())
            {
                m_publisher->publish(msg.getPayload());
            }
            else
            {
              /// Complain here.
            }
        }

    private:
        Adafruit_MQTT_Publish* m_publisher = nullptr; ///< The Adafruit implementation of an MQTT Publisher.
    };
}

#endif // MQTT_PUBLISHER_H