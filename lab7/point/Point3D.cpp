//
// Created by albert on 26.04.17.
//

#include <iostream>
#include <cmath>
#include <ostream>
#include "Point3D.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

Point3D::Point3D() {
    cout << "Konstruktor bezparametrowy 3D" << endl;
}
Point3D::Point3D(double x, double y, double z) : Point(x, y) {
    cout << "Konstruktor parametrowy 3D" << endl;
    z_ = z;
}
Point3D::~Point3D(){
    cout << "Desktruktor 3D" << endl;
}
double Point3D::Distance(const Point3D &other) const{
    return sqrt(pow(x_-other.GetX(),2)+pow(y_-other.GetY(),2)+pow(z_-other.GetZ(),2));
}

void Point3D::ToString(ostream &out) const{
    out << "(" << x_ << ";" << y_ << ";" << z_ << ")" << endl;
}

double Point3D::GetZ() const {
    return z_;
}