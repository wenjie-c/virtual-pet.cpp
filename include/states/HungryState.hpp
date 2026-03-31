#include <PetState.hpp>
#include <sys/types.h>
#ifndef HUNGRY_STATE_HPP
#define HUNGRY_STATE_HPP

class HungryState : public PetState 
{
    Pet * _pet;
    public:
    virtual void onEnter(Pet * pet)  override {_pet = pet; cout << "Entering to HungryState." << endl;}
    virtual void onEvent(const PetEvent  &event) override ;
    virtual PetState * onUpdate(ushort ticks) override ;
    virtual void draw() override ;
    virtual void onExit() override ;
};

#endif // HUNGRY_STATE_HPP