#include <iostream.h>


void age(int pd, int pm, int py, int bd, int bm, int by)
{
    int d, m, y;
    int md[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Handle leap year
    if ((py % 4 == 0 && py % 100 != 0) || (py % 400 == 0)) {
        md[1] = 29; // February has 29 days in a leap year
    }

    y = py - by;  // Calculate the year difference

    // If the current month is less than the birth month, reduce a year
    if (pm < bm) {
        y--;
        m = 12 - (bm - pm);
    }
    else {
        m = pm - bm;
    }

    // If the current day is less than the birth day, reduce a month
    if (pd < bd) {
        m--;
        d = md[pm - 1] - (bd - pd);  // Calculate the day difference
    }
    else {
        d = pd - bd;
    }

    cout << "Your age is: \n";
    cout << y << " years " << m << " months " << d << " days.";
}

int main()
{
    int pd, pm, py, bd, bm, by;

    // Input present date
    cout << "Enter the present date in the format dd mm yyyy: ";
    cin >> pd >> pm >> py;

    // Input birth date
    cout << "Enter the birth date in the format dd mm yyyy: ";
    cin >> bd >> bm >> by;

    // Call the age function to calculate the difference
    age(pd, pm, py, bd, bm, by);

    return 0;
}
