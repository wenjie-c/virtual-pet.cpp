#include <Pet.hpp>
#include <states/BoredState.hpp>
#include <states/HappyState.hpp>
#include <states/HungryState.hpp>
#include <states/SleepyState.hpp>
#include <states/SmellyState.hpp>
#include <sys/types.h>

void HappyState::onEvent(const PetEvent &event) {}
PetState *HappyState::onUpdate(ushort ticks) {
  if (_pet->getHungry() > threshold)
    return new HungryState();
  if (_pet->getSleep() > threshold)
    return new SleepyState();
  if (_pet->getSmell() > threshold)
    return new SmellyState();
  if (_pet->getBoredom() > threshold)
    return new BoredState();

  return NULL;
}
void HappyState::draw() { cout << "Your pet is happy." << endl; }
void HappyState::onExit() {}