#include <iostream.h>


class complex {
    int real;
    int img;

public:
    void input() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> img;
    }

    void output() {
        if (img < 0)
            cout << real << img << "i" << '\n';
        else
            cout << real << "+" << img << "i" << '\n';
    }

    friend complex add(int, complex);
    friend complex add(complex, complex);
};

// Function to add an integer to a complex number
complex add(int a, complex s2) {
    complex temp;
    temp.real = s2.real + a;
    temp.img = s2.img;
    return temp;
}

// Function to add two complex numbers
complex add(complex s1, complex s2) {
    complex s3;
    s3.real = s1.real + s2.real;
    s3.img = s1.img + s2.img;
    return s3;
}

int main() {
    complex s1, s2, sum1, sum2;
    int a;

    // Input the first complex number
    s1.input();

    // Input the second complex number
    s2.input();

    cout << "First complex number is: ";
    s1.output();

    cout << "Second complex number is: ";
    s2.output();

    // Input the integer to add to the complex number
    cout << "Enter an integer to add to the second complex number: ";
    cin >> a;

    // Perform the addition operations
    sum1 = add(a, s2);
    sum2 = add(s1, s2);

    // Display results
    cout << "Sum of integer and complex number: ";
    sum1.output();

    cout << "Sum of two complex numbers: ";
    sum2.output();

    return 0;
}
