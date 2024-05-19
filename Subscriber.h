#ifndef MQTT_SUBSCRIBER_H
#define MQTT_SUBSCRIBER_H

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "PubSubBase.h"

namespace Mqtt
{
    /**
     * @brief Function pointer for subscriber callbacks.
     * 
     * @todo I'd like to replace this with std::function<void(uint32_t)> somehow,
     *       but that doesn't seem possible and may not actually be wise...
     * 
     *       Also need to verify that I don't have the param and returns swapped...
     * 
     * @param uint32_t
     * 
     * @returns void
    */
    typedef void (*subCallback)(char*, uint16_t);

    template<typename msgType>
    class Subscriber : protected PubSubBase
    {
    public:
        Subscriber(Adafruit_MQTT_Client *client) : PubSubBase(client)
        {
            msgType msg;
            topic = msg.getTopic();
            m_subscriber = new Adafruit_MQTT_Subscribe(client, topic.c_str());
        }

        void subscribe()
        {
            m_client->subscribe(m_subscriber);
        }

        void subscribe(subCallback callback)
        {
            m_callback = callback;
            m_subscriber->setCallback(callback);
            m_client->subscribe(m_subscriber);
        }

    private:
        String topic;
        Adafruit_MQTT_Subscribe* m_subscriber;
        subCallback m_callback;

    };
}

#endif // MQTT_SUBSCRIBER_H