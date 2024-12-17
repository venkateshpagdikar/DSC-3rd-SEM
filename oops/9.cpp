#include <iostream.h> // Correct header


// Function overloads for swapping different types
void swap(int &ix, int &iy);
void swap(float &fx, float &fy);
void swap(char &cx, char &cy);

int main() {
    int ix, iy;
    float fx, fy;
    char cx, cy;

    // Input for integers
    cout << "Enter 2 integers: ";
    cin >> ix >> iy;

    // Input for floating point numbers
    cout << "Enter 2 floating point numbers: ";
    cin >> fx >> fy;

    // Input for characters
    cout << "Enter 2 characters: ";
    cin >> cx >> cy;

    // Output before swapping for integers
    cout << "\nIntegers: ";
    cout << "\nix = " << ix << "\niy = " << iy;
    swap(ix, iy); // Swap integers
    cout << "\nAfter swapping:";
    cout << "\nix = " << ix << "\niy = " << iy;

    // Output before swapping for floating point numbers
    cout << "\n\nFloating point numbers: ";
    cout << "\nfx = " << fx << "\nfy = " << fy;
    swap(fx, fy); // Swap floats
    cout << "\nAfter swapping:";
    cout << "\nfx = " << fx << "\nfy = " << fy;

    // Output before swapping for characters
    cout << "\n\nCharacters: ";
    cout << "\ncx = " << cx << "\ncy = " << cy;
    swap(cx, cy); // Swap characters
    cout << "\nAfter swapping:";
    cout << "\ncx = " << cx << "\ncy = " << cy;

    return 0;
}

// Swap function for integers
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Swap function for floating point numbers
void swap(float &a, float &b) {
    float temp;
    temp = a;
    a = b;
    b = temp;
}

// Swap function for characters
void swap(char &a, char &b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}
