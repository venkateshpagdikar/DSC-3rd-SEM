#include <iostream>
using namespace std;

class Swap {
    int x, y; // Declare variables of Swap class
public:
    // Parameterized constructor for inputs
    Swap(int x, int y) : x(x), y(y) {}

    // Friend function to swap values
    friend void swap(Swap&);
};

// Define the swap function outside the class scope
void swap(Swap& s) {
    // Local variable for swapping
    int temp = s.x;
    s.x = s.y;
    s.y = temp;

    cout << "\nBefore Swapping: x = " << s.y << ", y = " << temp;
    cout << "\nAfter Swapping: x= s.mere traoubleshooting.
