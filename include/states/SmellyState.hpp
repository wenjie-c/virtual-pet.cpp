#include <PetState.hpp>
#include <states/SleepyState.hpp>
#include <sys/types.h>
#ifndef SMELLY_STATE_HPP
#define SMELLY_STATE_HPP

class SmellyState : public SleepyState 
{
    Pet * _pet;
    public:
    virtual void onEnter(Pet * pet)  override {_pet = pet; cout << "Entering to SmellyState." << endl;}
    virtual void onEvent(const PetEvent  &event) override ;
    virtual PetState * onUpdate(ushort ticks) override ;
    virtual void draw() override ;
    virtual void onExit() override ;
};

#endif // SMELLY_STATE_HPP