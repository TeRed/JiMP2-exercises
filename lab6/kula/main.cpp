//
// Created by albert on 10.04.17.
//
#include "Kula.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0,0,0,10);

    cout << k.Kolo::pole() << endl;
    cout << k.pole() << endl;

    LiczbaRzeczywista a(12);
    LiczbaZespolona b(23,5);

    a.powitaj();         //Czesc!
    a.wypisz();          //12
    (a+a).wypisz();      //24

    b.powitaj();         //Czesc!
    b.wypisz();          //23 + 5I


    (b+b).wypisz();      //Co się wypisze?
}