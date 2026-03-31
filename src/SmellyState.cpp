#include <states/SmellyState.hpp>
#include <states/BoredState.hpp>
#include <Pet.hpp>
#include <sys/types.h>
void SmellyState::onEvent(const PetEvent &event) {}
PetState *SmellyState::onUpdate(ushort ticks) {
    if(_pet->getSleep() > threshold)
        return SleepyState::onUpdate(ticks);
    if(_pet->getSmell() < threshold)
        return new BoredState();
    return NULL;
}
void SmellyState::draw() { cout << "Your pet is smelly." <<endl;}
void SmellyState::onExit() {}