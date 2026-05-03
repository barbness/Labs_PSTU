#include "Time.h"

Time::Time(): min(0), sec(0) {}
Time::Time(int m, int s): min(m), sec(s){}
Time::Time(const Time& other): min(other.min), sec(other.sec){}

void Time::Normalize() {
    int total = min * 60 + sec;

    if (total < 0) {
        total = 0;
    }

    min = total / 60;
    sec = total % 60;
}

int Time::ToSeconds() const { return min * 60 + sec;}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        min = other.min;
        sec = other.sec;
    }

    return *this;
}

bool Time::operator>(const Time& other) const { return ToSeconds() > other.ToSeconds();}
bool Time::operator<(const Time& other) const {return ToSeconds() < other.ToSeconds();}
bool Time::operator==(const Time& other) const {return ToSeconds() == other.ToSeconds();}
bool Time::operator!=(const Time& other) const {return !(*this == other);}

Time Time::operator+(const Time& other) const {
    int total = ToSeconds() + other.ToSeconds();
    return Time(0, total);
}

Time Time::operator/(int value) const {
    if (value == 0) {
        return Time();
    }

    int total = ToSeconds() / value;
    return Time(0, total);
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.min << ":";

    if (t.sec < 10) {
        out << "0";
    }

    out << t.sec;

    return out;
}

istream& operator>>(istream& in, Time& t) {
    int m;
    int s;
    char c;

    in >> m >> c >> s;

    if (c == ':') {
        t.min = m;
        t.sec = s;
        t.Normalize();
    }
    else {
        in.setstate(ios::failbit);
    }

    return in;
}