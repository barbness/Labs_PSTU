#include "c_3.h" 

Time::Time() : min(0), sec(0) {}; 
Time::Time(int m, int s) : min(m), sec(s) {}; 
Time::Time(const Time& other) : min(other.min), sec(other.sec) {}; 

void Time::setMin(int m){min = m;};
void Time::setSec(int s){sec = s;};

int Time::getMin() const {return min;}; 
int Time::getSec() const {return sec;};

void Time::addSec(int s){
    int secs = this->sec + s; 
    this->min = secs/60; 
    this->sec = secs%60; 
} 
bool Time::operator==(const Time& other) {return (this->min == other.min && this->sec == other.sec);}
bool Time::operator!= (const Time& other) {return (this->min != other.min && this->sec != other.sec);}
