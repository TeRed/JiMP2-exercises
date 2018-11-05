#include "Palindrome.h"

using namespace std;

bool is_palindrome(string str) {
    if(str == string(str.rbegin(), str.rend()))
        return true;
    else
        return false;
}
