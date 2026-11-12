
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    string transactions[10];
    int count;

    // Stores the latest 10 transactions
    void addTransaction(const string& details) {
        if (count < 10) {
            transactions[count] = details;
            count++;
        } else {
            // Remove the oldest transaction
            for (int i = 1; i < 10; i++) {
                transactions[i - 1] = transactions[i];
            }
            transactions[9] = details;
        }
    }

public:
    SavingsAccount(string accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
    }

    // Defined inside the class
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance += amount;

        ostringstream record;
        record << "Deposit: Rs. " << fixed << setprecision(2) << amount;
        addTransaction(record.str());
    }

    // Declared inside, defined outside
    void withdraw(double amount);

    // Declared inside, defined outside
    void miniStatement() const;
};

// Member function defined outside the class
void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Invalid withdrawal amount\n";
        return;
    }

    balance -= amount;

    ostringstream record;
    record << "Withdrawal: Rs. " << fixed << setprecision(2) << amount;
    addTransaction(record.str());
}

// Member function defined outside the class
void SavingsAccount::miniStatement() const {
    cout << "\n----- MINI STATEMENT -----\n";
    cout << "Account Number: " << accountNumber << '\n';
    cout << "Current Balance: Rs. " << fixed
         << setprecision(2) << balance << '\n';

    cout << "\nLast " << count << " Transactions:\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << transactions[i] << '\n';
    }

    cout << "--------------------------\n";
}

int main() {
    SavingsAccount account("SA1001", 1000.00);

    account.deposit(100);
    account.withdraw(50);
    account.deposit(200);
    account.deposit(300);
    account.deposit(400);
    account.deposit(500);
    account.deposit(600);
    account.deposit(700);
    account.deposit(800);
    account.deposit(900);
    account.deposit(1000);

    account.miniStatement();

    return 0;
}
