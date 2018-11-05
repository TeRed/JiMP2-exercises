//
// Created by filiprze on 21.03.17.
//

#include "Point.h"
#include <cmath>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y){
    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){

}

double Point::Distance(const Point &inny) const{
    return sqrt(pow(GetX()-inny.GetX(),2)+pow(GetY()-inny.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const{
    return x_;
}

double Point::GetY() const{
    return y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}
