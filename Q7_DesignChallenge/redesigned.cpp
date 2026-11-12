
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;

    static const int CAPACITY = 50;
    string transactions[CAPACITY];

    int start;
    int count;

    void addTransaction(const string& details) {
        if (count < CAPACITY) {
            int index = (start + count) % CAPACITY;
            transactions[index] = details;
            count++;
        } else {
            // Overwrite the oldest transaction
            transactions[start] = details;
            start = (start + 1) % CAPACITY;
        }
    }

public:
    SavingsAccount(string accNo, double initialBalance)
        : accountNumber(accNo), balance(initialBalance),
          start(0), count(0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance += amount;
        addTransaction("Deposit: Rs. " + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal amount\n";
            return;
        }

        balance -= amount;
        addTransaction("Withdrawal: Rs. " + to_string(amount));
    }

    void miniStatement() const {
        cout << "\n----- MINI STATEMENT -----\n";
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Current Balance: Rs. " << balance << '\n';
        cout << "\nLast " << count << " Transactions:\n";

        for (int i = 0; i < count; i++) {
            int index = (start + i) % CAPACITY;
            cout << i + 1 << ". " << transactions[index] << '\n';
        }

        cout << "--------------------------\n";
    }
};

int main() {
    SavingsAccount account("SA1001", 1000);

    for (int i = 1; i <= 55; i++) {
        account.deposit(100);
    }

    account.miniStatement();

    return 0;
}
