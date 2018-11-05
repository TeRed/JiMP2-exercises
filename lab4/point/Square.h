//
// Created by filiprze on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include "Point.h"
#include <cmath>
class Square{
public:
    Square();
    Square(Point A, Point B, Point C, Point D);
    ~Square();

    Point GetA() const;
    Point GetB() const;
    Point GetC() const;
    Point GetD() const;

    void SetA(Point A);
    void SetB(Point B);
    void SetC(Point C);
    void SetD(Point D);

    double Circumference() const;
    double Area() const;

private:
    Point A_, B_, C_, D_;
};
#endif //JIMP_EXERCISES_SQUARE_H
