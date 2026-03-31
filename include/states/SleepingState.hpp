#include <PetState.hpp>
#include <sys/types.h>
#ifndef SLEEPING_STATE_HPP
#define SLEEPING_STATE_HPP

class SleepingState : public PetState {
  Pet *_pet;

public:
  virtual void onEnter(Pet *pet) override { _pet = pet; cout << "Entering to SleepingState." << endl;}
  virtual void onEvent(const PetEvent &event) override;
  virtual PetState *onUpdate(ushort ticks) override;
  virtual void draw() override;
  virtual void onExit() override;
};

#endif // SLEEPING_STATE_HPP