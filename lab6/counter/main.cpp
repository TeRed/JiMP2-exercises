//
// Created by przemek on 06.04.17.
//

#include <iostream>
#include "Counter.h"
#include <fstream>
using ::std::cout;
using ::std::endl;
using ::abc::Word;
using ::abc::Counts;

int main() {
    std::ofstream out("test3.txt");
    out << "Polskie źnaki \n żaba, kołek    ,. noga.";
    abc::WordCounter A("/home/przemek/test3.txt");
    out.close();
//    abc::Counts c;
//    abc::Counts c1;

//    cout << (c < c1) << endl;
//    cout << A["noga"];
    cout << A;
    return 0;
}