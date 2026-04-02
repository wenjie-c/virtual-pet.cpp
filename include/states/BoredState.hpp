#include <PetState.hpp>
#include <states/SmellyState.hpp>
#include <sys/types.h>
#ifndef BORED_STATE_HPP
#define BORED_STATE_HPP

class BoredState : public PetState
{
    public:
    virtual void onEnter(Pet * pet) override {_pet = pet; cout << "Entering to BoredState." << endl;}
    virtual void onEvent(const PetEvent  &event) override;
    virtual PetState * onUpdate(ushort ticks) override;
    virtual void draw() override;
    virtual void onExit() override;
};

#endif // BORED_STATE_HPP