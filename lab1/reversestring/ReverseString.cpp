#include <iostream>
#include "ReverseString.h"

using namespace std;

string reverse(string str) {
    string result;
    while(str.length()) {
        result += str[str.length() - 1];
        str.pop_back();
    }
    return result;
}
