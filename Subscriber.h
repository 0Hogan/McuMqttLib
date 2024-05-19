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
     *       but that doesn't seem possible (at least, not without implementing the 
     *       MQTT protocol myself, which I may yet do, but not just yet) and may not
     *       actually be wise...
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
        /**
         * @brief Construct a new Subscriber object
         * 
         * @param client The connection to the client responsible for publishing
         *               messages to the subscriber.
         */
        Subscriber(Adafruit_MQTT_Client *client) : PubSubBase(client)
        {
            msgType msg;
            topic = msg.getTopic();
            m_subscriber = new Adafruit_MQTT_Subscribe(client, topic.c_str());
        }

        /**
         * @brief Subscribes to the appropriate topic without specifying a callback.
         * 
         * @note This probably isn't overly useful right now, since m_subscriber is
         *       private and there isn't yet a function to access the most recently
         *       published data...
         * 
         */
        void subscribe()
        {
            m_client->subscribe(m_subscriber);
        }

        /**
         * @brief Subscribes to the appropriate topic.
         * 
         * @param callback The function to execute upon receiving a published message.
         */
        void subscribe(subCallback callback)
        {
            m_callback = callback;
            m_subscriber->setCallback(callback);
            m_client->subscribe(m_subscriber);
        }

    private:
        String topic; ///< The topic to which the subscriber should subscribe.
        Adafruit_MQTT_Subscribe* m_subscriber; ///< The Adafruit MQTT subscriber.
        subCallback m_callback; ///< The callback currently specified for execution upon receiving a message.

    };
}

#endif // MQTT_SUBSCRIBER_H