
#include <iostream>
using namespace std;

// Parcel class
class Parcel
{
public:
    double weight;
    bool express;
    bool insured;

    Parcel(double w, bool e, bool i)
    {
        weight = w;
        express = e;
        insured = i;
    }
};

// Overload 1: Weight in grams
double charge(int grams)
{
    return (grams / 1000.0) * 50;
}

// Overload 2: Weight in kilograms
double charge(double kg, bool express = false,
              bool insured = false)
{
    double total = kg * 50;

    if (express)
        total += 30;

    if (insured)
        total += 20;

    return total;
}

// Overload 3: Parcel object
double charge(const Parcel& p)
{
    return charge(p.weight, p.express, p.insured);
}

int main()
{
    Parcel p(3.0, true, true);

    cout << "Call 1 - Grams: "
         << charge(2000) << endl;

    cout << "Call 2 - Float: "
         << charge(2.0f) << endl;

    cout << "Call 3 - Kilograms: "
         << charge(2.0) << endl;

    cout << "Call 4 - Express: "
         << charge(2.0, true) << endl;

    cout << "Call 5 - Express and Insurance: "
         << charge(2.0, true, true) << endl;

    cout << "Call 6 - Parcel Object: "
         << charge(p) << endl;

    return 0;
}
