
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int calculate(int x) {
    return x * 2 + 1;
}

int main() {
    volatile long long result = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++) {
        result = result + calculate(i);
    }

    auto stop = high_resolution_clock::now();

    cout << "Normal function time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    cout << "Result: " << result << '\n';
}
