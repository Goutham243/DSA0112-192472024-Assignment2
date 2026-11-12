
#include <iostream>
using namespace std;

// Call by Value
void concessionByValue(double fee, int percent)
{
    fee = fee - (fee * percent / 100);
    cout << "Inside Value Function: " << fee << endl;
}

// Call by Reference
void concessionByReference(double& fee, int percent)
{
    fee = fee - (fee * percent / 100);
    cout << "Inside Reference Function: " << fee << endl;
}

// Call by Pointer
void concessionByPointer(double* fee, int percent)
{
    *fee = *fee - (*fee * percent / 100);
    cout << "Inside Pointer Function: " << *fee << endl;
}

int main()
{
    double fee1 = 45000;
    double fee2 = 45000;
    double fee3 = 45000;

    cout << "Original Hostel Fee: 45000" << endl;

    concessionByValue(fee1, 10);
    cout << "Stored Fee after Value: " << fee1 << endl;

    concessionByReference(fee2, 10);
    cout << "Stored Fee after Reference: " << fee2 << endl;

    concessionByPointer(&fee3, 10);
    cout << "Stored Fee after Pointer: " << fee3 << endl;

    return 0;
}
