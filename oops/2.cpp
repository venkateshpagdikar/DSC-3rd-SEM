#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    // Check for leap year
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void age(int pd, int pm, int py, int bd, int bm, int by) {
    int d, m, y;
    int md[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Adjust for leap year
    if (isLeapYear(py)) md[1] = 29;

    // Validate input
    if (py < by || (py == by && pm < bm) || (py == by && pm == bm && pd < bd)) {
        cout << "Error: Present date is earlier than birth date.\n";
        return;
    }

    y = py - by;

    if (pm < bm) {
        y--; // Borrow a year
        m = 12 + pm - bm;
    } else {
        m = pm - bm;
    }

    if (pd < bd) {
        m--; // Borrow a month
        if (m < 0) {
            m = 11; // Borrow from a year
            y--;
        }
        d = md[(pm == 1 ? 11 : pm - 2)] + pd - bd; // Handle wraparound for months
    } else {
        d = pd - bd;
    }

    cout << "Your age is:\n";
    cout << y << " years, " << m << " months, " << d << " days.\n";
}

int main() {
    int pd, pm, py, bd, bm, by;
    cout << "Enter the present date in the format dd mm yyyy: ";
    cin >> pd >> pm >> py;
    cout << "Enter the birth date in the format dd mm yyyy: ";
    cin >> bd >> bm >> by;
    age(pd, pm, py, bd, bm, by);
    return 0;
}
