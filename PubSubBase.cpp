#include "PubSubBase.h"

/**
 * @brief Connects to the MQTT client server (if not already connected).
 * 
 * @todo Need to determine how to attempt retries without stopping code execution (i.e. no delays).
 * 
 * @return true Connection is established.
 * @return false Connection could not be established.
 */
bool Mqtt::PubSubBase::connectToClient()
{
    if (m_client->connected())
    {
        return true;
    }

    const int8_t MQTT_CONNECTED_CODE = 0;
    uint8_t retriesRemaining = 3;
    int8_t connectionErrorCode;
    while ((connectionErrorCode = m_client->connect()) != MQTT_CONNECTED_CODE)
    {
        Serial.println(m_client->connectErrorString(connectionErrorCode));
        Serial.println("Retrying MQTT connection in 5 seconds...");
        m_client->disconnect();
        // delay(5000);  // wait 5 seconds
        // retries--;

        // if (retries < 1)
        // {
        //     // Couldn't successfully establish a connection
        //     return false;
        // }
        return false;
    }

    // Connection was successfully established
    return true;
}