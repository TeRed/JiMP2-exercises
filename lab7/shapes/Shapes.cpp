//
// Created by albert on 26.04.17.
//

#include "Shapes.h"
#include "iostream"
#include <cmath>

using ::std::cout;
using ::std::endl;

namespace shape {
    Circle::Circle(unsigned int r) : Shape() {
        if(r < 0) radius = 0;
        else radius = r;
    }

    void Circle::draw() {
        int r = radius;
        int size;
        size = 2*radius + 1;

        for(int y = 0; y < size; ++y){
            for(int x = 0; x < size; ++x){
                if(radius > 4)	{
                    if((radius * radius) <= ((x-radius)*(x-radius) + (y-radius)*(y-radius)))	cout << " ";
                    else cout << "#";
                }
                else{
                    if((radius * radius) < ((x-radius)*(x-radius) + (y-radius)*(y-radius)))	cout << " ";
                    else cout << "#";
                }
            }
            cout << endl;
        }
    }

    Square::Square(unsigned int s) : Shape() {
        if(s < 0) side = 0;
        else side = s;
    }

    void Square::draw() {
        for(int i = 0; i < side; i++) {
            for(int j = 0; j < side; j++){
                cout << "#";
            }
            cout << endl;
        }
    }

    Triangle::Triangle(unsigned int s) : Shape() {
        if(s < 0) side = 0;
        else side = s;
    }

    void Triangle::draw() {
        for(int i = 0; i < side; i++){
            for(int j = 0; j < side-i; j++){
                cout << "#";
            }
            cout << endl;
        }
    }
}