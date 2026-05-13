#include <iostream> 

class Time {
    int min;
    int sec;

public:
    Time();
    Time(int min, int sec);
    Time(const Time& other);

    int getMin() const;
    int getSec() const;

    void setMin(int m);
    void setSec(int s);

    void addSec(int s);
    bool operator==(const Time& other);
    bool operator!=(const Time& other);
    bool operator<(const Time& other) const;
    Time operator+(const Time& other) const;
    Time operator/(int n) const;
    Time operator/(const Time& other) const;

    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};