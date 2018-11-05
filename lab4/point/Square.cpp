//
// Created by filiprze on 21.03.17.
//

#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

Square::Square():A_(0,0),B_(0,0),C_(0,0),D_(0,0) {
    cout << "Konstruktor bezparametryuczny" << endl;
}

Square::Square(Point A, Point B, Point C, Point D) {
    cout << "Konstruktor parametryczny " << endl;
    A_ = A;
    B_ = B;
    C_ = C;
    D_ = D;
}

Square::~Square() {
    cout << "Destruktor !" << endl;
}

Point Square::GetA() const {
    return A_;
}

Point Square::GetB() const {
    return B_;
}

Point Square::GetC() const {
    return C_;
}

Point Square::GetD() const {
    return D_;
}

void Square::SetA(Point A) {
    A_ = A;
}

void Square::SetB(Point B) {
    B_ = B;
}

void Square::SetC(Point C) {
    C_ = C;
}

void Square::SetD(Point D) {
    D_ = D;
}

double Square::Circumference() const {
    double  x = std::min(A_.Distance(B_), A_.Distance(C_));
    return 4*(x);
}

double Square::Area() const {
    double  x = std::min(A_.Distance(B_), A_.Distance(C_));
    return pow(x,2);
}
