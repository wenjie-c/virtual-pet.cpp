#include <states/HungryState.hpp>
#include <states/SleepyState.hpp>
#include <Pet.hpp>
#include <sys/types.h>

void HungryState::onEvent(const PetEvent &event) {PetState::onEvent(event);}
PetState *HungryState::onUpdate(ushort ticks) {
    if(_pet->getHungry() < threshold)
        return new SleepyState();
    return NULL;
}
void HungryState::draw() { cout << "Your pet is starving." <<endl;}
void HungryState::onExit() {}