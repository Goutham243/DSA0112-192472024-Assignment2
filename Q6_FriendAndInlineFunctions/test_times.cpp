
#include <iostream>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}

bool earlier(const Time& a, const Time& b) {
    return (a.h < b.h) || (a.h == b.h && a.m < b.m);
}

int main() {
    Time beforeNoon(11, 50);
    Time afterNoon(12, 10);
    Time same1(10, 30);
    Time same2(10, 30);

    cout << "Across noon: "
         << minutesBetween(beforeNoon, afterNoon) << " minutes\n";

    cout << "Earlier across noon: "
         << boolalpha << earlier(beforeNoon, afterNoon) << '\n';

    cout << "Same time difference: "
         << minutesBetween(same1, same2) << " minutes\n";

    cout << "Same time earlier: "
         << earlier(same1, same2) << '\n';

    return 0;
}
