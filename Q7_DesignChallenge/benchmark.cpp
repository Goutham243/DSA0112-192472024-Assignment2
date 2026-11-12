
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int CAPACITY = 50;
const int TOTAL = 10000000;

class ShiftingBuffer {
    int data[CAPACITY];
    int count = 0;

public:
    void add(int value) {
        if (count < CAPACITY) {
            data[count++] = value;
        } else {
            for (int i = 1; i < CAPACITY; i++) {
                data[i - 1] = data[i];
            }
            data[CAPACITY - 1] = value;
        }
    }

    int last() const {
        return data[CAPACITY - 1];
    }
};

class CircularBuffer {
    int data[CAPACITY];
    int start = 0;
    int count = 0;

public:
    void add(int value) {
        if (count < CAPACITY) {
            data[(start + count) % CAPACITY] = value;
            count++;
        } else {
            data[start] = value;
            start = (start + 1) % CAPACITY;
        }
    }

    int last() const {
        return data[(start + count - 1) % CAPACITY];
    }
};

int main() {
    ShiftingBuffer original;
    auto start1 = steady_clock::now();

    for (int i = 0; i < TOTAL; i++) {
        original.add(i);
    }

    auto end1 = steady_clock::now();

    CircularBuffer redesigned;
    auto start2 = steady_clock::now();

    for (int i = 0; i < TOTAL; i++) {
        redesigned.add(i);
    }

    auto end2 = steady_clock::now();

    cout << "Original last value: " << original.last() << '\n';
    cout << "Redesigned last value: " << redesigned.last() << '\n';

    cout << "Original shifting time: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms\n";

    cout << "Circular buffer time: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms\n";

    return 0;
}
