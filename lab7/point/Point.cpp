//
// Created by albert on 26.04.17.
//

#include <cmath>
#include <ostream>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

Point::Point() : x_(0), y_(0) {
    cout << "Konstruktor bezparametrowy 2D" << endl;
}

Point::Point(double x, double y){
    cout << "Konstruktor parametrowy 2D" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    cout << "Destruktor 2D" << endl;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(x_ - other.GetX(), 2)+pow(y_ - other.GetY(), 2));
}

void Point::ToString(ostream &out) const{
    out << "(" << x_ << ";" << y_ << ")" << endl;
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

std::ostream& operator<<(std::ostream& out, const Point& pkt) {
    out << "(" << pkt.x_ << ";" << pkt.y_ << ")" << endl;
}