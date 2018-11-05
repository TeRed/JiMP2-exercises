//
// Created by filiprze on 21.03.17.
//

#include "Square.h"
using ::std::cout;
using ::std::endl;

int main(){
    Point a(1,1);
    Point b(3,3);
    Point c(1,3);
    Point d(3,1);
    Square kwadrat(a, b, c, d);

    cout << "Obwod: " << kwadrat.Circumference() << endl;
    cout << "Pole: " << kwadrat.Area() << endl;

    return 0;
}

