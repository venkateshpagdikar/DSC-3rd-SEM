#include <iostream>
using namespace std;

class student {
    int rno;
    char name[20];
    int age, m1, m2, m3;

public:
    float avg;
    void readdata();
    void average();
    void display();
};

void student::readdata() {
    cout << "Enter the roll no: ";
    cin >> rno;
    cout << "\nEnter the name: ";
    cin >> name;
    cout << "\nEnter the age: ";
    cin >> age;
    cout << "Enter the marks of 3 subjects: ";
    cin >> m1 >> m2 >> m3;
}

void student::average() {
    avg = (m1 + m2 + m3) / 3.0; // Ensure floating-point division
}

void student::display() {
    cout << rno << "\t" << name << "\t" << m1 << "\t" << m2 << "\t" << m3 << "\t" << avg << "\n";
}

int main() {
    student s[10];
    int n, i;
    float total = 0;

    cout << "Enter the number of students: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        s[i].readdata();
        s[i].average();
        total += s[i].avg;
    }

    cout << "Roll no\tName\tM1\tM2\tM3\tAverage\n";
    for (i = 0; i < n; i++) {
        s[i].display();
    }

    cout << "Total average: " << total / n << "\n";

    return 0;
}
