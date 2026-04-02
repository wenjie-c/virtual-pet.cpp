#include <Pet.hpp>
#include <states/SleepingState.hpp>
#include <cstddef>

void Pet::onEvent(const PetEvent &event) {

  switch (event.getType()) {
  
  case EventType::ON_SLEEP: {
    _state->onExit();
    delete _state;
    _state = new SleepingState();
    _state->onEnter(this);
  }
  /*
  case EventType::ON_FEED:
    feed();
    break;
  case EventType::ON_CLEAN:
    clean();
    break;
  case EventType::ON_PLAY:
    play();
    break;
    */
  case EventType::NaE:
    _state->onEvent(event);
    break;
    
  default:
  // Everything else will be handled by the state
    _state->onEvent(event);
  //throw Utils::PetException("Unknown event type");
  }
}

void Pet::onUpdate(ushort ticks) {
  PetState *next = _state->onUpdate(ticks);
  if (next != NULL) {
    next->onEnter(this);
    _state->onExit();
    delete _state;
    _state = next;
  }
  _hungry = Utils::clamp(0, 255, _hungry + ticks * hungryIncrement);
  _sleep = Utils::clamp(0, 255, _sleep + ticks * sleepIncrement);
  _smell = Utils::clamp(0, 255, _smell + ticks * smellIncrement);
  _boredom = Utils::clamp(0, 255, _boredom + ticks * boredomIncrement);

  
}
void Pet::draw() {
  cout << "Hungry: " << (int)_hungry << " || ";
  cout << "Sleep: " << (int)_sleep << " || ";
  cout << "Smell: " << (int)_smell << " || ";
  cout << "Boredom: " << (int)_boredom << endl;
  cout << "----------" << endl;
  _state->draw();
  cout << "----------" << endl;
}

#pragma region internals
void Pet::feed() { _hungry = Utils::clamp(0, 255, _hungry - hungryDecrement); }
void Pet::sleep(ushort ticks) { _sleep = Utils::clamp(0, 255, _sleep - sleepDecrement * ticks / ticksPerHour); }
void Pet::clean() { _smell = Utils::clamp(0, 255, _smell - smellDecrement); }
void Pet::play() {
  _boredom = Utils::clamp(0, 255, _boredom - boredomDecrement);
}
#pragma endregion
