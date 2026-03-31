#include <PetEvent.hpp>
EventType PetEvent::getType() const { return _type; }
string PetEvent::getArgs() const { return _args; }