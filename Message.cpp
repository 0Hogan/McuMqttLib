#include <string>

#include "Message.h"

/**
 * @brief Packages the message into a payload to send over Mqtt.
 * 
 * @return const char* The payload as a C-style string (i.e. a null terminated array of characters).
 */
const char* Mqtt::Message::getPayload() const
{
    JsonDocument doc = convertMsgToJson();
    std::string payload;
    serializeMsgPack(doc, payload);
    return payload.c_str();
}