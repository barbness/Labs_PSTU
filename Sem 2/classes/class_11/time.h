#pragma once
#include <iostream>

using namespace std;

class Time {
private:
    int min;
    int sec;

    void Normalize();

public:
    Time();
    Time(int m, int s);
    Time(const Time& other);

    int ToSeconds() const;

    Time& operator=(const Time& other);

    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;

    Time operator+(const Time& other) const;
    Time operator/(int value) const;

    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& t);
};