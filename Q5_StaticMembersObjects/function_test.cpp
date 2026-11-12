
#include <iostream>
#include <string>
using namespace std;

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    string name;

public:
    BusTicket(string n) : seat(0), name(n) {
        if (issued < CAPACITY) {
            seat = ++issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat)
                      : string("Waiting")) << '\n';
    }
};

int BusTicket::issued = 0;

void createTickets(string name1, string name2) {
    BusTicket t1(name1);
    BusTicket t2(name2);

    t1.print();
    t2.print();

    cout << "Total issued: " << BusTicket::count() << "\n\n";
}

int main() {
    cout << "First function call:\n";
    createTickets("Asha", "Bala");

    cout << "Second function call:\n";
    createTickets("Chitra", "Dev");

    return 0;
}
