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

static ushort hungryDecrement = 33;
static ushort sleepDecrement = 33;
static ushort smellDecrement = 60;
static ushort boredomDecrement = 60;

static ushort hungryIncrement = 3;
static ushort sleepIncrement = 1;
static ushort smellIncrement = 3;
static ushort boredomIncrement = 3;

static ushort threshold = 200;
static ushort ticksPerHour = 12; // one ticks is 5 minutes


#endif // UTILS_HPP