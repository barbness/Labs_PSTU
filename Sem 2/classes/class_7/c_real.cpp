#include "c_7.h"

Time::Time(): mins(0), secs(0) {}
Time::Time(int m, int s): mins(m), secs(s){}
Time::Time(const Time& other): mins(other.mins), secs(other.secs){}

void Time::setMins(int m) {mins = m;}
void Time::setSec(int s) { secs = s;}

int Time::getMins() {return mins;}
int Time::getSecs() {return secs;}

std::ostream& operator<<(std::ostream& out, const Time& a){
    out << a.mins << ":" << a.secs;
    return out;
}