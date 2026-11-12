
#include <iostream>
using namespace std;

// Dangerous function
int& badReference()
{
    int local = 50;
    return local;
}

int main()
{
    cout << "Demonstrating dangling reference warning" << endl;

    return 0;
}
