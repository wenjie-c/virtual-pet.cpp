#include <cstdint>
#include <definitions.h>

namespace Utils {
    void clear() {cout << "\033[2J\033[1;1H";}
    ushort clamp(ushort min, ushort max, int a) 
    {
        if(a < min) return min;
        if(a >= max) return max;
        return a;
    }
    /*
    class PetException : public exception {
        string _message;
        public:
        PetException(const string message) : _message(message) {}
        const char * what() const  noexcept override {return _message.c_str();}
    };
    */
}