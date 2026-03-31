#include <Pet.hpp>
#include <states/SleepingState.hpp>
#include <sys/types.h>

void SleepingState::onEvent(const PetEvent &event)  {}
PetState *SleepingState::onUpdate(ushort ticks) {
  if (_pet->getSleep() != 1) {
    _pet->sleep();
    return NULL;
  } else {
    return new HappyState();
  }
}
void SleepingState::draw() { cout << "Your pet is sleeping." << endl; }
void SleepingState::onExit() {}