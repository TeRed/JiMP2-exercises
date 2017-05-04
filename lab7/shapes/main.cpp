//
// Created by albert on 26.04.17.
//

#include <iostream>
#include "Shapes.h"

using ::shape::Circle;
using ::shape::Shape;
using ::shape::Square;
using ::shape::Triangle;
using ::std::cout;
using ::std::endl;

int main() {
    Shape *various_shapes[3];
    various_shapes[0] = new Square(6);
    various_shapes[1] = new Circle(5);
    various_shapes[2] = new Triangle(6);

    various_shapes[0]->draw();
    cout << endl;
    various_shapes[1]->draw();
    cout << endl;
    various_shapes[2]->draw();
    cout << endl;

    for(int i = 0; i < 3; i++) delete various_shapes[i];

    return 0;
}