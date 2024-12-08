#include <iostream.h> // Use standard C++ header


class B {
public:
    virtual void s() = 0; // Pure Virtual Function
};

class D : public B {
public:
    void s() { // Explicitly mark as override for clarity
        cout << "Virtual Function in Derived class\n";
    }
};

int main() {
    B* b;
    D dobj;
    b = &dobj;
    b->s(); // Calls the overridden function in the derived class
    return 0; // Ensure main returns an integer
}
