#include<iostream.h>
#include<conio.h>

class student {
    int rollno;
    char name[30], branch[30];
public:
    void getdata() {
        cout << "Enter the roll no: ";
        cin >> rollno;
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the branch: ";
        cin >> branch;
    }
    void displaydata() {
        cout << "\nRoll number: " << rollno;
        cout << "\nName: " << name;
        cout << "\nBranch: " << branch;
    }
};

class exam : public student {
protected:
    int mark[6];
public:
    void getdata();
    void displaydata();
};

void exam::getdata() {
    student::getdata();
    cout << "Enter the marks\n";
    for (int i = 0; i < 6; i++) {
        cin >> mark[i];
    }
}

void exam::displaydata() {
    student::displaydata();
    cout << "\nThe marks are:\n";
    for (int i = 0; i < 6; i++) {
        cout << mark[i] << " " << "\n";
    }
}

class result : public exam {
    int total;
public:
    result() {
        total = 0;
    }
    void calculate();
    void displaydata() {
        exam::displaydata();
        cout << "\nTotal: " << total;
    }
};

void result::calculate() {
    exam::getdata();
    for (int i = 0; i < 6; i++) {
        total = total + mark[i];
    }
}

int main() {
    result r;
    cout << "Enter the data of students: ";
    r.calculate();
    cout << "Student Details\n";
    r.displaydata();
    return 0;
}
