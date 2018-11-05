//
// Created by albert on 08.03.17.
//
#include "Polybius.h"
#include <map>
#include <iostream>

using namespace std;

const char m[5][5] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'k'},
    {'l', 'm', 'n', 'o', 'p'},
    {'q', 'r', 's', 't', 'u'},
    {'v', 'w', 'x', 'y', 'z'}
};

string find(char x) {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5 ; j++) {
            if(m[i][j] == x) {
                string to_return = "";
                to_return += to_string(i + 1);
                to_return += to_string(j + 1);

                return to_return;
            }
        }
}

std::string PolybiusCrypt(std::string message) {
    string return_string = "";
    for(int i = 0; i < message.size(); i++) {
        message[i] = tolower(message[i]);
        if(message[i] == ' ') continue;
        if(message[i] == 'j') message[i] = 'i';
        return_string += find(message[i]);
    }

    return return_string;
}
std::string PolybiusDecrypt(std::string crypted) {
    string return_string = "";
    int x, y;
    for(int i = 0; i < crypted.size(); i += 2) {
        x = (int)crypted[i] - 48;
        y = (int)crypted[i+1] - 48;
        return_string += m[x - 1][y - 1];
    }

    return return_string;
}