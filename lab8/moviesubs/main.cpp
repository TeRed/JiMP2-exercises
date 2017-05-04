//
// Created by albert on 02.05.17.
//

#include <iostream>
#include "MovieSubtitles.h"

int main() {
    moviesubs::MicroDvdSubtitles ms;
    stringstream in("{0}{250}TEXT TEXT\n{260}{300}NEWLINE\n");
    stringstream out;
    ms.ShiftAllSubtitlesBy(1000, 24, &in, &out);

    std::cout << out.str();
    return 0;
}