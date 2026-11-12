
#include <iostream>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

// TODO 1 completed
int minutesBetween(const Time& a, const Time& b) {
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    int difference = timeA - timeB;

    return difference < 0 ? -difference : difference;
}

// TODO 2 completed
bool earlier(const Time& a, const Time& b) {
    if (a.h < b.h) {
        return true;
    }

    if (a.h > b.h) {
        return false;
    }

    return a.m < b.m;
}

int main() {
    Time departure(9, 45), arrival(13, 10);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    return 0;
}
