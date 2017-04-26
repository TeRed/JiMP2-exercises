//
// Created by albert on 26.04.17.
//

#include <iostream>
#include "Point.h"
#include "Point3D.h"

using ::std::cout;
using ::std::endl;

int main() {
    cout << "Tworzenie punktu 2D a potem 3D :" << endl;
    Point point2d(3,2);
    Point3D point3d(4,8,9);
    cout << endl;

    cout << "Wypisanie punktow 2D a potem 3D za pomocą funkcji ToString :" << endl;
    point2d.ToString(cout);
    point3d.ToString(cout);
    cout << endl;

    cout << "Wypisanie punktow 2D a potem 3D za pomocą operatora << :" << endl;
    cout << point2d;
    cout << point3d;
    cout << endl;

    cout << "Wywołanie funkcji Distance dla punktu 2D oraz z punktem 3D jako argumentem :" << endl;
    cout << "Dystans: " << point2d.Distance(point3d) << endl;
    cout << endl;

    cout << "Tutaj wywołane zostaną destruktory :" << endl;

    /*Odpowiedzi do zadań

    Zadanie 5

    Przy wywołaniu konstruktora obiektu klasy dziedziczącej,
    najpierw wywoływany jest konstruktor klasy bazowej a potem kontruktor klasy potomnej.

    Przy wywołaniu destruktora jest odwrotnie.
    Najpierw wywoływany jest destruktor klasy potomnej a potem destruktor klasy bazowej.

    Zadanie 6

    Przy wywołaniu punkt2d.distance(punkt3d) punkt3d traktowany jest jak punkt 2d (rzutowany).
    Liczony jest dystans między punktem 2d oraz punktem 2d stworzonym z atrybutów punktu 3d dziedziczonych po punkcie 2d
    (drugi punkt 2d jest obiektem klasy bazowej zawartej w punkcie 3d).

    Zadanie 7

    Odpowiedź jest podobna jak w zadaniu 6.
    Punkt 3d jest rzutowany na punkt 2d i wywoływany jest operator << dla klasy bazowej zawartej w punkcie 3d.*/

    return 0;
}