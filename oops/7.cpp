#include <iostream>
using namespace std;

class matrix {
    int a[10][10], m, n; // Matrix elements and dimensions
public:
    // Default constructor
    matrix() : m(0), n(0) {}

    void getdata();
    int operator==(matrix);              // Compare dimensions
    matrix operator+(matrix);            // Add matrices
    matrix operator-(matrix);            // Subtract matrices
    friend ostream& operator<<(ostream&, matrix&); // Output matrix
};

void matrix::getdata() {
    cout << "Enter the size of the matrix (rows and columns): ";
    cin >> m >> n;
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

int matrix::operator==(matrix cm) {
    return (m == cm.m && n == cm.n);
}

matrix matrix::operator+(matrix am) {
    matrix temp;
    temp.m = m;
    temp.n = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp.a[i][j] = a[i][j] + am.a[i][j];
        }
    }
    return temp;
}

matrix matrix::operator-(matrix sm) {
    matrix temp;
    temp.m = m;
    temp.n = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp.a[i][j] = a[i][j] - sm.a[i][j];
        }
    }
    return temp;
}

ostream& operator<<(ostream &out, matrix &d) {
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.n; j++) {
            out << d.a[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

int main() {
    matrix m1, m2, m3, m4;
    cout << "Enter details for the first matrix:\n";
    m1.getdata();
    cout << "Enter details for the second matrix:\n";
    m2.getdata();

    if (m1 == m2) {
        m3 = m1 + m2;
        m4 = m1 - m2;
        cout << "\nThe addition of two matrices:\n" << m3;
        cout << "\nThe subtraction of two matrices:\n" << m4;
    } else {
        cout << "\nThe two matrices are not compatible for addition or subtraction.\n";
    }
    return 0;
}
