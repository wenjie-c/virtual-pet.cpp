#include <Pet.hpp>
#include <states/SleepingState.hpp>
#include <sys/types.h>

void SleepingState::onEvent(const PetEvent &event)  {}
PetState *SleepingState::onUpdate(ushort ticks) {
  if (_pet->getSleep() > sleepDecrement) {
    _pet->sleep(ticks);
    return NULL;
  } else {
    return new HappyState();
  }
}
void SleepingState::draw() { cout << "Your pet is sleeping." << endl; }
void SleepingState::onExit() {}