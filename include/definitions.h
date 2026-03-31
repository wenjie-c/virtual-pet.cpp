#include <cstdint>
#include <sys/types.h>
#define VERSION 1.0

#include <iostream>
#include <exception>
#include <string>
using namespace std;

#ifndef UTILS_HPP
#define UTILS_HPP
class Pet;

namespace Utils {

    typedef unsigned short int ushort;
    //typedef unsigned char ushort;


    void clear() ;
    ushort clamp(ushort min, ushort max, int a) ;
    class PetException : public exception {
        string _message;
        public:
        PetException(const string message) : _message(message) {}
        const char * what() const  noexcept override {return _message.c_str();}
    };
}

static char hungryDecrement = 33;
static char sleepDecrement = 33;
static char smellDecrement = 60;
static char boredomDecrement = 60;

static char hungryIncrement = 3;
static char sleepIncrement = 1;
static char smellIncrement = 3;
static char boredomIncrement = 3;

static char threshold = 200;
static char ticksPerHour = 12; // one ticks is 5 minutes


#endif // UTILS_HPP