#include <iostream>
#include <cstdlib>
#include "Palindrome.h"

using namespace std;

void menu() {
    cout << endl;
    cout << "Opcje:" << endl;
    cout << "1 Sprawdź palindrom" << endl;
    cout << "2 Wyjście" << endl << endl;
    cout << "Podaj opcje:" << endl;
}

int main() {
    int key = 0;
    string str;

    while(key != 2) {
        if(key == 1) {
            cout << "Podaj string: ";
            cin.ignore();
            getline(cin, str);

            if(is_palindrome(str))
                cout << "String \"" << str << "\" jest palindromem." << endl;
            else
                cout << "String \"" << str << "\" nie jest palindromem." << endl;
        }

        menu();

        cin >> key;
    }
    return 0;
}