#include<iostream.h>
#include<process.h>

class reserve {
    char name[20], s[20], d[20];
    int age, date;
public:
    float chrg;
    void getdata() {
        cout << "Enter the name of the passenger: ";
        cin >> name;
        cout << "\nEnter the source: ";
        cin >> s;
        cout << "\nEnter the destination: ";
        cin >> d;
        cout << "\nEnter the age of the person: ";
        cin >> age;
        cout << "\nEnter the date of travel (date): ";
        cin >> date;
        cout << "\nEnter the ticket charge: ";
        cin >> chrg;
    }
    void display() {
        cout << "\nName: " << name
             << "\nSource: " << s
             << "\nDestination: " << d
             << "\nAge: " << age
             << "\nDate of journey: " << date;
    }
};

class adult : public reserve {
public:
    adult() {
        getdata();
        display();
        cout << "\nTicket charge: " << chrg;
    }
};

class child : public reserve {
public:
    child() {
        getdata();
        display();
        cout << "\nTicket charge: " << 0.5 * chrg;
    }
};

class snr : public reserve {
public:
    snr() {
        getdata();
        display();
        cout << "\nTicket charge: " << 0.25 * chrg;
    }
};

int main() {
    int ch = 0; // Initialize `ch` to prevent uninitialized variable issues
    cout << "\nPassenger category\n1. Adult\n2. Child\n3. Senior citizen\n4. Exit\n";
    while (ch != 4) {
        cout << "\nEnter the choice: ";
        cin >> ch;
        switch (ch) {
        case 1: {
            adult a;
            break;
        }
        case 2: {
            child c;
            break;
        }
        case 3: {
            snr s;
            break;
        }
        case 4:
            exit(0);
        default:
            cout << "\nEnter a valid choice\n";
        }
    }
    return 0;
}
