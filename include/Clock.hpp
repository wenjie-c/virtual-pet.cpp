#include <string>
#include <sys/types.h>

#ifndef CLOCK_HPP
#define CLOCK_HPP
using namespace std;
class Clock{
    public:
    int totalTime;
    int hoursPerSkip;
    ushort deltaTicks; // old nextTicks
    ushort nextTicks;
    Clock(int hps) : totalTime(0), hoursPerSkip(hps), nextTicks(1), deltaTicks(0) {}

    void onUpdate();
    void skipHour();
    string whatHour() const;
};

#endif //CLOCK_HPP