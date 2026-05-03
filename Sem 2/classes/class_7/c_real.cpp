#include "c_7.h"

Time::Time(): mins(0), secs(0) {}
Time::Time(int m, int s): mins(m), secs(s){}
Time::Time(const Time& other): mins(other.mins), secs(other.secs){}

std::ostream& operator<<(std::ostream& out, const Time& a){
    out << a.mins << ":" << a.secs;
}