# MQTT Tools

# Summary

A repository that provides a simple and consistent interface for an implementation of the MQTT protocol.

This library actually relies upon Adafruit's MQTT library at the moment. I'm slightly tempted to try to implement my own version of the MQTT protocol (it'd be fun and educational), but that would be a future development, and isn't the case right now. So, to use it, you'll have to install Adafruit's MQTT library.

# To-Do's

* Periodic Publisher - a specialization of the Publisher class that publishes a message at specified intervals. It might be obvious to some, but I come from more of a ROS2 background, so much of the terminology and framework comes from the ROS2 way of doing things as opposed to the "MQTT way" of doing things. In any case, the idea of a periodic publisher seems useful to me (though I don't yet have a specific use-case in mind), so I'd like to add it in.
* Namespace support - Right now, the namespace of a topic must be declared in the topic name. It might be nice to add in support for a general level namespace that can prefix the actual topic name. (e.g. namespace "iot/" and topic name "sprinklers/commands" => topic "iot/sprinklers/commands"). Possibly overkill, but maybe nice.
* Templated Message? - ROS2 auto-generates the message definitions based on a general template - that might be the way to go here, especially if I could tie in some VS Code settings or something... Otherwise, there's going to be a lot of boilerplate code that needs to be typed up by hand with each and every message definition. I could also possibly handle namespace support here if I were auto-generating the actual message class...