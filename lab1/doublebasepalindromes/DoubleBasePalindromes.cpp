#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum= 0;
    for(int i=1; i<max_vaule_exculsive; i+=2){
        std::string str = std::to_string(i);
        std::string str1 = decToBin(i);
        if(is_palindrome(str) && is_palindrome(str1)) sum+=i;
    }
    return sum;
}

std::string decToBin(int dec){
    std::string newStr = "";
    while(dec>0){
        newStr += (dec%2);
        dec/=2;
    }
    return newStr;
}

bool is_palindrome(std::string str){
    size_t size = str.length();

    for(int i=0;i<(size/2);i++){
        if(str[i] != str[(size - i - 1)]){
            return false;
        }
    }
    return true;
}
