#include <PetState.hpp>
#include <sys/types.h>
#ifndef HAPPY_STATE_HPP
#define HAPPY_STATE_HPP

class HappyState : public PetState {
  Pet *_pet;

public:
  virtual void onEnter(Pet *pet) override { _pet = pet; cout << "Entering to HappyState." << endl;}
  virtual void onEvent(const PetEvent &event) override;
  virtual PetState *onUpdate(ushort ticks) override;
  virtual void draw() override;
  virtual void onExit() override;
};

#endif // HAPPY_STATE_HPP