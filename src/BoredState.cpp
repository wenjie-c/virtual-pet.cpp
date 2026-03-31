#include <states/BoredState.hpp>
#include <states/HappyState.hpp> // if everything is fullfilled
#include <Pet.hpp>
#include <sys/types.h>

void BoredState::onEvent(const PetEvent &event) {}
PetState *BoredState::onUpdate(ushort ticks) {
    if(_pet->getSmell() > threshold)
        return SmellyState::onUpdate(ticks);
    
    if(_pet->getBoredom() < threshold)
        return new HappyState();
    return NULL;
}
void BoredState::draw() { cout << "Your pet is bored." <<endl;}
void BoredState::onExit() {}