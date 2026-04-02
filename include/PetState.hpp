#include <cstddef>
#include <definitions.h>
#include <PetEvent.hpp>
#include <sys/types.h>

#ifndef PET_STATE_HPP
#define PET_STATE_HPP
class Pet;

class PetState{
    protected:
    Pet * _pet;
    public:
    virtual void onEnter(Pet * pet);
    virtual void onEvent(const PetEvent  &event);
    virtual PetState * onUpdate(ushort ticks);
    virtual void draw();
    virtual void onExit();
    virtual ~PetState();
};

#endif //PET_STATE_HPP