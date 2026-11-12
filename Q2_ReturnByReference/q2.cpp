
#include <iostream>
using namespace std;

// Return by Reference
int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Return by Const Reference
const int& highestMarkConst(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

// Return by Value (Copy)
int highestMarkCopy(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int main()
{
    int marks[5] = {75, 82, 90, 68, 85};

    cout << "Original Highest Mark: "
         << highestMark(marks, 5) << endl;

    // Modify original array using returned reference
    highestMark(marks, 5) += 2;

    cout << "After Moderation: "
         << highestMark(marks, 5) << endl;

    cout << "Const Reference Result: "
         << highestMarkConst(marks, 5) << endl;

    cout << "Copy Result: "
         << highestMarkCopy(marks, 5) << endl;

    cout << "Final Marks: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    return 0;
}
