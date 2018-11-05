//
// Created by albert on 11.03.17.
//
#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <string>
#include <vector>
#include <algorithm>
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary);
bool up_key(char key[], int key_length);
#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
