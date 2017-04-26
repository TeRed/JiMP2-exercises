//
// Created by albert on 10.04.17.
//

#include "Kula.h"
#include "cmath"
#include <iostream>

using std::cout;
using std::endl;

double Kolo::pole() {
    return M_PI * r * r;
}
Kolo::Kolo(double x, double y, double r) {
    this->x = x;
    this->y = y;
    this->r = r;
}
Kula::Kula(double x, double y, double z, double r): Kolo(x, y, r){
    this->z = z;
}

double Kula::pole() {
    return (4 * M_PI * r * r * r)/3;
}
