#include <iostream>
using namespace std;

class acc {
    int no;
    float bal; // Changed to float to handle decimal values

public:
    // Constructor for initializing account
    acc() : no(0), bal(0) {}
    acc(int ain, float bin = 0) : no(ain), bal(bin) {}

    // Method to manually get account details
    void get() {
        cout << "\nEnter the account number: ";
        cin >> no;
        cout << "Enter the balance: ";
        cin >> bal;
    }

    // Display account information
    void display() const {
        cout << "\nThe Account number: " << no;
        cout << "\nBalance: " << bal;
    }

    // Transfer money between accounts
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
    acc a1, a2(2), a3(3, 100.5); // Using constructors for initialization

    // Input details for the first account
    a1.get();

    // Display initial account information
    cout << "\nAccount information \n";
    a1.display();
    a2.display();
    a3.display();

    // Transfer money from account 1 to account 2
    cout << "\nHow much money is to be transferred from account 1 to account 2: ";
    cin >> amount;
    a1.transfer(a2, amount);

    // Display updated account information
    cout << "\nUpdated account information \n";
    a1.display();
    a2.display();
    a3.display();

    return 0;
}
