#include <iostream>
#include <cstring> // For strcpy and strcat
using namespace std;

class MyString {
    char str[100]; // Increased buffer size for safer concatenation
public:
    // Default constructor
    MyString() {
        strcpy(str, "");
    }

    // Constructor with const char* parameter
    MyString(const char* s) {
        strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& s) {
        strcpy(str, s.str);
    }

    // Overloaded + operator to concatenate strings
    MyString operator+(const MyString& s2) const {
        MyString temp; // Create a new object for the result
        strcpy(temp.str, str); // Copy the current string
        strcat(temp.str, " "); // Add a space
        strcat(temp.str, s2.str); // Concatenate the second string
        return temp;
    }

    // Friend function to overload << for output
    friend ostream& operator<<(ostream& print, const MyString& s);
};

// Overloading << operator
ostream& operator<<(ostream& print, const MyString& s) {
    print << s.str;
    return print;
}

// Main function
int main() {
    MyString s1("HERBERT");
    cout << "First string is: " << s1 << "\n";

    MyString s2(s1);
    cout << "Copied first string: " << s2 << "\n";

    MyString s3("SCHIELD");
    cout << "Second string is: " << s3 << "\n";

    MyString s5 = s1 + s3;
    cout << "Concatenated string is: " << s5 << "\n";

    return 0;
}
