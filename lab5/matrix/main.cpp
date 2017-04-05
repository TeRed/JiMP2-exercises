//
// Created by albert on 03.04.17.
//

#include <iostream>
#include "Matrix.h"

using ::std::cout;
using ::std::endl;
using ::algebra::Matrix;

int main() {
    algebra::Matrix m("[    2     1  1i-9.67 ;   1    1i-9    1.1i1.1   ;   8   9    10   ]");
//    algebra::Matrix m1{{1.0i, 0.,   0.},
//                       {0.,   1.0i, 0.},
//                       {0.,   0.,   1.0i}};
//    cout << m1.Print() << endl;
//    cout << "11111111111111111111" << endl;
//    cout << m.Print();
//    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
//    cout << m2.Print();
//    cout << "222222222222222222222" <<  endl;
//
//    (m.Add(m2));
//
    cout << m.Print() << endl;
    Matrix m2(0, 0);
    m2 = std::move(m);

    cout << m2.getElement(0, 0);


    cout << m2.Print() << endl;

//    cout << m.Size().first << " " << m.Size().second << endl;
    cout << m.Print() << endl;


    return 0;
}