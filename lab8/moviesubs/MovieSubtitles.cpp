//
// Created by albert on 02.05.17.
//

#include <cmath>
#include <iostream>
#include <stdexcept>
#include "MovieSubtitles.h"

using ::moviesubs::MicroDvdSubtitles;
using ::moviesubs::SubtitleEndBeforeStart;
using ::std::string;
using ::std::cout;
using ::std::endl;
using ::std::invalid_argument;

SubtitleEndBeforeStart::SubtitleEndBeforeStart() {
    at_line = 0;
    what_line = "";
}
int SubtitleEndBeforeStart::LineAt() const {
    return at_line;
}
string SubtitleEndBeforeStart::what() const {
    stringstream to_return;
    to_return << "At line ";
    to_return << at_line;
    to_return << ": ";
    to_return << what_line;

    return to_return.str();
};
void SubtitleEndBeforeStart::inc() {
    at_line++;
};
void SubtitleEndBeforeStart::set_what(string what) {
    what_line = what;
}

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out)  throw
(NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat) {
    if(fps <= 0){
        throw invalid_argument("Invalid argument");
    }

    int shift = floor((delay*fps)/1000); //how many frames need to shift
    string start = "", end = "", line;
    int line_indicator, start_int, end_int;
    SubtitleEndBeforeStart sebs;
    while(!(*in).eof()) {
        getline(*in, line);
        sebs.inc();
        if(line == "") break;
        if(line[0] != '{') throw InvalidSubtitleLineFormat();
        for(line_indicator = 1; line_indicator < line.length(); line_indicator++) {
            if(line[line_indicator] == '}'){
                if(line[line_indicator + 1] != '{') throw InvalidSubtitleLineFormat();
                line_indicator += 2;
                break;
            }
            else start += line[line_indicator];
        }
        if(line_indicator == line.length()) throw InvalidSubtitleLineFormat();
        for(;line_indicator < line.length(); line_indicator++) {
            if(line[line_indicator] == '}'){
                line_indicator++;
                break;
            }
            else end += line[line_indicator];
        }
        if(line_indicator == line.length()) throw InvalidSubtitleLineFormat();
        if(!start.length() || !end.length()) throw InvalidSubtitleLineFormat();
        for(int i = 0; i < start.length(); i++) if(!isdigit(start[i])) throw InvalidSubtitleLineFormat();
        for(int i = 0; i < end.length(); i++) if(!isdigit(end[i])) throw InvalidSubtitleLineFormat();

        (*out) << "{";
        start_int = atoi(start.c_str()) + shift;
        if(start_int < 0) throw NegativeFrameAfterShift();
        (*out) << start;
        (*out) << "}{";
        end_int = atoi(end.c_str()) + shift;
        if(end_int < 0) throw NegativeFrameAfterShift();
        (*out) << end;
        (*out) << '}';
        if(end < start){
            sebs.set_what(line);
            throw sebs;
        }
        line.erase(0, line_indicator);
        (*out) << line << endl;



        start = end = "";
    }
}