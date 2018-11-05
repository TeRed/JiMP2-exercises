//
// Created by albert on 08.03.17.
//
#include "Polybius.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    
    //Pliki wejściowe i argumenty programu użytkownik musi podać sam!
    
    ifstream infile(argv[1]);
    ofstream outfile (argv[2], ios_base::in | ios_base::app);
    string line;

    if(!infile){
        cout << "Nie można otworzyć pliku wejściowego!" << endl;
        return 0;
    }
    if(!outfile) {
        cout << "Nie można otworzyć pliku wyjściowego!" << endl;
        return 0;
    }

    while(!infile.eof()) {
        getline(infile, line);
        if(atoi(argv[3]) == 1) outfile << PolybiusCrypt(line) << endl;
        else outfile << PolybiusDecrypt(line) << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}