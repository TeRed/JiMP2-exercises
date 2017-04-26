//
// Created by albert on 10.04.17.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H
#include <iostream>

using std::cout;
using std::endl;

class Kolo{
protected:
    double x, y, r;
public:
    Kolo(){};
    Kolo(double x, double y, double r);
    ~Kolo(){};
    double pole();
};

class Kula : public Kolo {
protected:
    double z;
public:
    Kula(): Kolo() {};
    Kula(double x, double y, double z, double r);
    ~Kula(){};
    double pole();
};
class LiczbaRzeczywista {
protected:
    double re;
public:
    LiczbaRzeczywista(double r){re=r;}
    void wypisz(){
        cout << re << endl;
    }
    void powitaj(){
        cout << "Czesc!" << endl;
    }

    LiczbaRzeczywista operator+(const LiczbaRzeczywista& r){
        LiczbaRzeczywista rr(re+r.re);
        return rr;
    }

};

class LiczbaZespolona : public LiczbaRzeczywista{
protected:
    double im;
public:
    LiczbaZespolona(double re, double i):LiczbaRzeczywista(re){im=i;}
    void wypisz(){
        cout << re << " + " << im << "i" << endl;
    }
};
#endif //JIMP_EXERCISES_KULA_H
