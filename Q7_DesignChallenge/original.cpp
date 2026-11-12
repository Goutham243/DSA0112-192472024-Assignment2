
#include <iostream>
using namespace std;

class OriginalBuffer {
private:
    static const int CAPACITY = 50;
    int transactions[CAPACITY];
    int count;

public:
    OriginalBuffer() : count(0) {}

    void addTransaction(int value) {
        if (count < CAPACITY) {
            transactions[count] = value;
            count++;
        } else {
            // Shift all elements to discard the oldest
            for (int i = 1; i < CAPACITY; i++) {
                transactions[i - 1] = transactions[i];
            }

            transactions[CAPACITY - 1] = value;
        }
    }

    int getLast() const {
        return transactions[count - 1];
    }
};

int main() {
    OriginalBuffer account;

    for (int i = 1; i <= 55; i++) {
        account.addTransaction(i);
    }

    cout << "Original shifting design\n";
    cout << "Latest transaction: " << account.getLast() << '\n';
    cout << "Expected stored transactions: 50\n";

    return 0;
}
