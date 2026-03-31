#include <Clock.hpp>
#include <math.h>
#include <sstream>
#include <cmath>


void Clock::onUpdate()
{
    totalTime += nextTicks;
    if(totalTime >= 288) totalTime = 0;
    deltaTicks = nextTicks;
    nextTicks = 1;
}
void Clock::skipHour()
{
    nextTicks = 12 - totalTime % 12;
}
string Clock::whatHour() const{
    // 24 h format
    stringstream ss;
    int hours = floor(totalTime / 12);
    int minutes = (totalTime % 12 * 5);
    ss << hours << " : ";
    ss << minutes << endl;
    return ss.str();
}