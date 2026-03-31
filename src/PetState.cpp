#include <PetState.hpp>
#include <sys/types.h>

void PetState::onEnter(Pet *pet) {}
void PetState::onEvent(const PetEvent &event) {}
PetState *PetState::onUpdate(ushort ticks) { return NULL; }
void PetState::draw() {}
void PetState::onExit() {}
PetState::~PetState() {}