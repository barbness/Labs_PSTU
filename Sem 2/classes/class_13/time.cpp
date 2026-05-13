#include "time.h"

Time::Time(): min(0), sec(0) {}

Time::Time(int min, int sec)
{
    this->min = min;
    this->sec = sec;

    if (this->sec >= 60){
        this->min = this->min + this->sec / 60;
        this->sec = this->sec % 60;
    }

    if (this->sec < 0){
        this->min = this->min + this->sec / 60;
        this->sec = this->sec % 60;

        if (this->sec < 0){
            this->sec = this->sec + 60;
            this->min--;
        }
    }
}

Time::Time(const Time& other): min(other.min), sec(other.sec) {}

int Time::getMin() const {return min;}
int Time::getSec() const {return sec;}

void Time::setMin(int m) {
    min = m;

    if (min < 0) {
        min = 0;
    }
}

void Time::setSec(int s){
    sec = s;

    if (sec >= 60){
        min = min + sec / 60;
        sec = sec % 60;
    }

    if (sec < 0){
        min = min + sec / 60;
        sec = sec % 60;

        if (sec < 0){
            sec = sec + 60;
            min--;
        }
    }
}

bool Time::operator==(const Time& other) const { return min == other.min && sec == other.sec;}

bool Time::operator<(const Time& other) const {
    int t1;
    int t2;

    t1 = min * 60 + sec;
    t2 = other.min * 60 + other.sec;

    return t1 < t2;
}

Time Time::operator+(const Time& other) const{
    int t1;
    int t2;
    int result;

    t1 = min * 60 + sec;
    t2 = other.min * 60 + other.sec;

    result = t1 + t2;

    return Time(result / 60, result % 60);
}

Time Time::operator/(int n) const {
    int t;
    int result;

    if (n == 0){
        return Time(0, 0);
    }

    t = min * 60 + sec;
    result = t / n;

    return Time(result / 60, result % 60);
}

std::istream& operator>>(std::istream& in, Time& t) {
    in >> t.min >> t.sec;

    if (t.sec >= 60){
        t.min = t.min + t.sec / 60;
        t.sec = t.sec % 60;
    }

    if (t.sec < 0){
        t.min = t.min + t.sec / 60;
        t.sec = t.sec % 60;

        if (t.sec < 0){
            t.sec = t.sec + 60;
            t.min--;
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.min << ":" << t.sec;
    return out;
}