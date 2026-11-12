
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> marks = {75, 82, 90, 68, 85};

    int& highest = marks[2];

    cout << "Highest mark before growth: "
         << highest << endl;

    // Force vector reallocation
    marks.reserve(marks.capacity() + 10);

    cout << "Highest mark after growth: "
         << marks[2] << endl;

    // Use the vector directly, not the old reference

    return 0;
}
