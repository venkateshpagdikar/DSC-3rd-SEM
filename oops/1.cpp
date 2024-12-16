#include <iostream>
using namespace std;

class student {
    int rno;
    char Name[20];
    int age, M1, M2, M3;

public:
    float avg;
    void readdata() {
        cout << "\nEnter the roll no.: ";
        cin >> rno;
        cout << "\nEnter the name: ";
        cin >> Name;
        cout << "\nEnter the age: ";
        cin >> age;
        cout << "Enter the marks of three subjects: ";
        cin >> M1 >> M2 >> M3;
    }
    void average() {
        avg = (M1 + M2 + M3) / 3.0; // Ensure floating-point division
    }
    void display() {
        cout << rno << "\t\t" << Name << "\t" << M1 << "\t" << M2 << "\t" << M3 << "\t" << avg << "\n";
    }
};

int main() {
    student s[10]; // Corrected array declaration
    int n, i;
    float total = 0;
    cout << "\nEnter the number of students: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        s[i].readdata();
        s[i].average();
        total += s[i].avg;
    }
    cout << "Roll no.\tName\tM1\tM2\tM3\tAverage\n";
    for (i = 0; i < n; i++)
        s[i].display();
    cout << "Total average: " << total / n;
    return 0;
}
