#include <PetState.hpp>
#include <states/HungryState.hpp>
#include <sys/types.h>
#ifndef SLEEPY_STATE_HPP
#define SLEEPY_STATE_HPP

class SleepyState : public PetState
{
    public:
    virtual void onEnter(Pet * pet)  override {_pet = pet; cout << "Entering to SleepyState." << endl;}
    virtual void onEvent(const PetEvent  &event) override ;
    virtual PetState * onUpdate(ushort ticks) override ;
    virtual void draw() override ;
    virtual void onExit() override ;
};

#endif // SLEEPY_STATE_HPP