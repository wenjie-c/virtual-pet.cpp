#include <states/SleepyState.hpp>
#include <states/HungryState.hpp> // next if it under the threshold
#include <states/SmellyState.hpp>
#include <Pet.hpp>
#include <sys/types.h>

void SleepyState::onEvent(const PetEvent &event) {}
PetState *SleepyState::onUpdate(ushort ticks) {
    if(_pet->getHungry() > threshold)
        return HungryState::onUpdate(ticks);
    if(_pet->getSleep() < threshold)
        return new SmellyState();
    return NULL;
}
void SleepyState::draw() { cout << "Your pet is sleepy." <<endl;}
void SleepyState::onExit() {}

