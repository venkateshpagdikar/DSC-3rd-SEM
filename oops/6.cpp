#include <iostream.h>
#include <string.h> // Use string.h for strcpy and strcat


class MyString {
    char str[100];
public:
    MyString() {
        strcpy(str, "");
    }

    MyString(const char* s) {
        strcpy(str, s);
    }

    MyString(const MyString& s) {
        strcpy(str, s.str);
    }

    MyString operator+(const MyString& s2) const {
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, " ");
        strcat(temp.str, s2.str);
        return temp;
    }

    friend ostream& operator<<(ostream& print, const MyString& s);
};

ostream& operator<<(ostream& print, const MyString& s) {
    print << s.str;
    return print;
}

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
