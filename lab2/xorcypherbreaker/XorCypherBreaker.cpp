//
// Created by albert on 11.03.17.
//
#include <iostream>
#include "XorCypherBreaker.h"

using namespace std;

bool up_key(char key[], int key_length){
    key[key_length - 1]++;
    for(int i = key_length - 1; i >= 0; i--){
        if(key[i] == 123){
            if((i - 1) >= 0){
            key[i] = 'a';
            key[i - 1]++;
            }
            else return false;
        }
    }
    return true;
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary) {

    if(key_length < 1) return "";

    char *key = new char[key_length];
    for(int i = 0; i < key_length; i++) key[i] = 'a';

    int key_position = 0;
    int count = 0; //count how many words is known with this key
    string word = ""; //used for creating words and to return key
    char x;

    do{
        for(int i = 0; i < cryptogram.size(); i++){
            if(word.size() > 60) break;
            x = cryptogram[i] ^ key[key_position];
            key_position = ++key_position % key_length;
            if(x != ' ') {
                word += x;
                continue;
            }

            if (find(dictionary.begin(),dictionary.end(), word) != dictionary.end()) count++;

            if(count > (0.05)*cryptogram.size()){
                word = "";
                for(int j = 0; j < key_length; j++) word += key[j];
                delete [] key;
                return word;
            }
            word = "";
        }
        count = 0;
        word = "";
        key_position = 0;
    }while(up_key(key, key_length));

    delete [] key;
    return "";
}
