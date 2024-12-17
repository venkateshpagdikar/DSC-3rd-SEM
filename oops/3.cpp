d#include <iostream.h>

class acc {
    int no;
    float bal;

public:
    acc() : no(0), bal(0) {}
    acc(int ain, float bin = 0) : no(ain), bal(bin) {}

    void get() {
        cout << "\nEnter the account number: ";
        cin >> no;
        cout << "Enter the balance: ";
        cin >> bal;
    }

    void display() const {
        cout << "\nThe Account number: " << no;
        cout << "\nBalance: " << bal;
    }

    void transfer(acc &a, float amt) {
        if (amt > bal) {
            cout << "\nTransfer failed: Insufficient balance in account " << no << ".\n";
        } else {
            bal -= amt;
            a.bal += amt;
            cout << "\nTransfer successful: " << amt << " transferred from account " << no
                 << " to account " << a.no << ".\n";
        }
    }
};

int main() {
    float amount;
    acc a1, a2(2), a3(3, 100.5);

    a1.get();

    cout << "\nAccount information \n";
    a1.display();
    a2.display();
    a3.display();

    cout << "\nHow much money is to be transferred from account 1 to account 2: ";
    cin >> amount;
    a1.transfer(a2, amount);

    cout << "\nUpdated account information \n";
    a1.display();
    a2.display();
    a3.display();

    return 0;
}
