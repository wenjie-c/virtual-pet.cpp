#include <Game.hpp>
#include <cstdio>
#include <iostream>

void Game::draw() {
  Utils::clear();
  pet.draw();
  cout << "----------" << endl;
  cout << clock.whatHour();
  cout << "----------" << endl;

  cout << "Select an action:" << endl;
  cout
      << "1) Feed 2) Put on sleep 3) Clean 4) Play with it 5) Skip hour 0) Exit"
      << endl;
}
void Game::handleEvents() {
  PetEvent event;
  bool outOfSelection = true;
  while (outOfSelection) {
    string option;
    cin >> option;
    switch (option[0]) {
    case '1':
      event = PetEvent(EventType::ON_FEED);
      outOfSelection = false;
      break;
    case '2':
      event = PetEvent(EventType::ON_SLEEP);
      outOfSelection = false;
      break;
    case '3':
      event = PetEvent(EventType::ON_CLEAN);
      outOfSelection = false;
      break;
    case '4':
      event = PetEvent(EventType::ON_PLAY);
      outOfSelection = false;
    case '5':
      clock.skipHour();
      outOfSelection = false;
      break;
    case '0':
      _exitFlag = true;
      outOfSelection = false;
      break;
    }
  }

  pet.onEvent(event);
}
void Game::onExit() { pet.release(); }

void Game::run() {

  while (!_exitFlag) {
    draw();
    handleEvents();
    clock.onUpdate(); // It updates here to catch skip hour correctly
    pet.onUpdate(clock.deltaTicks);
  }
  onExit();
}