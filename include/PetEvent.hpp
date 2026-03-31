#include <definitions.h>
#include <string>
#ifndef PET_EVENT_HPP
#define PET_EVENT_HPP

enum EventType { ON_FEED, ON_CLEAN, ON_SLEEP, ON_PLAY, NaE};

class PetEvent{
    EventType _type;
    string _args;
    public:
    PetEvent(EventType etype = EventType::NaE, string args = ""  ) : _type(etype) , _args(args) {}
    EventType getType() const;
    string getArgs() const;
};

#endif