#include <PetState.hpp>
#include <cstdint>
#include <states/HappyState.hpp>
#include <sys/types.h>
#ifndef PET_HPP
#define PET_HPP

class Pet {
  PetState *_state;
  ushort _hungry;
  ushort _sleep;
  ushort _smell;
  ushort _boredom;

public:
  Pet(ushort hungry = 0, ushort sleep = 0, ushort smell = 0, ushort boredom = 0)
      : _hungry(hungry), _sleep(sleep), _smell(smell), _boredom(boredom), _state(new HappyState()) 
      {_state->onEnter(this);}

  void onEvent(const PetEvent &event);
  void onUpdate(ushort ticks);
  void draw();
  void release() {
    _state->onExit();
    delete _state;
  }

#pragma region Getters
  ushort getHungry() const { return _hungry; }
  ushort getSleep() const { return _sleep; }
  ushort getSmell() const { return _smell; }
  ushort getBoredom() const { return _boredom; }
#pragma endregion

#pragma region Setters
  void setSleep(ushort sleep) { _sleep = sleep; }
#pragma endregion

#pragma region eventHandler
  void feed();
  void sleep(ushort ticks);
  void clean();
  void play();
#pragma endregion
};

#endif // PET_HPP