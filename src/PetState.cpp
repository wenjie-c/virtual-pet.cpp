#include <PetState.hpp>
#include <sys/types.h>
#include <Pet.hpp>

void PetState::onEnter(Pet *pet) {_pet = pet;}
void PetState::onEvent(const PetEvent &event) 
{
    switch (event.getType()) {
  
        case EventType::ON_FEED:
          _pet->feed();
          break;
        case EventType::ON_CLEAN:
          _pet->clean();
          break;
        case EventType::ON_PLAY:
          _pet->play();
          break;
        case EventType::NaE:
          
          break;
          
        default:
        throw Utils::PetException("Unknown event type");
        }
}
PetState *PetState::onUpdate(ushort ticks) { return NULL; }
void PetState::draw() {}
void PetState::onExit() {}
PetState::~PetState() {}