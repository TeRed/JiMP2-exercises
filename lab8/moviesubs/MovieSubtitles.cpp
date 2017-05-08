#include "MovieSubtitles.h"
#include <iostream>
#include <cmath>
#include <string>

using ::std::invalid_argument;
using ::std::endl;
using ::std::to_string;

namespace moviesubs {
    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_number, string line_string) {
        exception_line_number = line_number;
        exception_line_string = line_string;
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return exception_line_number;
    }

    string SubtitleEndBeforeStart::what() const {
        stringstream to_return;
        to_return << "At line ";
        to_return << exception_line_number;
        to_return << ": ";
        to_return << exception_line_string;

        return to_return.str();
    };

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out)  throw
    (NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat, invalid_argument) {
        if(fps <= 0){
            throw invalid_argument("Invalid argument");
        }

        string start = ""; //start frame
        string end = ""; //end frame
        string line; //current line
        int shift = floor((delay*fps)/1000); //how many frames need to shift
        int line_iterator = 1; //iterate current line
        int start_int, end_int; //to change string start/end to int
        int subtitleEndBeforeStartLineCounter = 0; //count already read lines for one of exceptions

        while(getline(*in, line)) {
            start = end = ""; //preparing variables each loop
            line_iterator = 1;
            subtitleEndBeforeStartLineCounter++;

            //Read start, end and rest of line from line and check for exceptions
            if(line[0] != '{') throw InvalidSubtitleLineFormat();
            while(isdigit(line[line_iterator])) start += line[line_iterator++];
            if(line[line_iterator] != '}' || line[line_iterator + 1] != '{' || start == "") throw InvalidSubtitleLineFormat();
            line_iterator += 2;
            while(isdigit(line[line_iterator])) end += line[line_iterator++];
            if(line[line_iterator] != '}' || end == "") throw InvalidSubtitleLineFormat();
            line_iterator++; //indicate first real subtitle char

            //new frames int numbers
            start_int = atoi(start.c_str()) + shift;
            end_int = atoi(end.c_str()) + shift;

            if(start_int < 0 || end_int < 0) throw NegativeFrameAfterShift();
            if(start_int > end_int) {
                throw SubtitleEndBeforeStart(subtitleEndBeforeStartLineCounter, line);
            }

            (*out) << "{";
            (*out) << start_int;
            (*out) << "}{";
            (*out) << end_int;
            (*out) << '}';
            line.erase(0, line_iterator);
            (*out) << line << endl;
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int shift_time, int fps, std::stringstream *in, std::stringstream *out) throw
    (NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat, OutOfOrderFrames, invalid_argument) {
        if(fps <= 0){
            throw invalid_argument("Invalid argument");
        }

        string line = "block_loop_start";
        string time_to_out;
        string part_of_time; //used for reading start/end time
        int start = 0, end = 0;
        int micro; //used to translate between hours/minutes/seconds/miliseconds
        int subtitleEndBeforeStartLineCounter = 0; //count already read lines for one of exceptions
        int line_iterator; //iterate current line
        int block_iterator; //iterate lines in blocks in structure in SubRip
        char separators[] = {'0', ':', ':', ','}; //time separators

        do{
            if(line == "block_loop_start") {
                block_iterator = 1;
                subtitleEndBeforeStartLineCounter++;
                continue;
            }
            if(line == "") {
                block_iterator = 1;
                subtitleEndBeforeStartLineCounter++;
                (*out) << line << endl;
                continue;
            }

            if(block_iterator == 1 && to_string(subtitleEndBeforeStartLineCounter) != line) throw OutOfOrderFrames();

            if(block_iterator != 2) {
                (*out) << line << endl;
            }
            else{ //line with times to translate
                line_iterator = 0;

                start = 0;
                micro = 3600000;

                //reading start time
                for(int i = 0; i < 4; i++) {
                    part_of_time = "";
                    if (i != 0 && line[line_iterator++] != separators[i]) throw InvalidSubtitleLineFormat();
                    if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                    part_of_time += line[line_iterator++];
                    if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                    part_of_time += line[line_iterator++];
                    if(i == 3) {
                        if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                        part_of_time += line[line_iterator++];
                        start += atoi(part_of_time.c_str());
                        continue;
                    }
                    start += atoi(part_of_time.c_str()) * micro;
                    micro /= 60;
                }

                line_iterator += 5;

                end = 0;
                micro = 3600000;

                //reading end time
                for(int i = 0; i < 4; i++) {
                    part_of_time = "";
                    if (i != 0 && line[line_iterator++] != separators[i]) throw InvalidSubtitleLineFormat();
                    if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                    part_of_time += line[line_iterator++];
                    if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                    part_of_time += line[line_iterator++];
                    if(i == 3) {
                        if(!isdigit(line[line_iterator])) throw InvalidSubtitleLineFormat();
                        part_of_time += line[line_iterator++];
                        end += atoi(part_of_time.c_str());
                        continue;
                    }
                    end += atoi(part_of_time.c_str()) * micro;
                    micro /= 60;
                }

                start += shift_time;
                end += shift_time;

                if(start < 0 || end < 0) throw NegativeFrameAfterShift();
                if(start > end) throw SubtitleEndBeforeStart(subtitleEndBeforeStartLineCounter, line);

                print_time(start, separators, out);
                (*out) << " --> ";
                print_time(end, separators, out);
                (*out) << endl;
            }

            block_iterator++;
        }while(getline(*in, line));
    }

    //translate time in miliseconds to SubRip format
    void print_time(int miliseconds, char separators[], stringstream *out) {

        int time_shift[4];
        time_shift[0]= miliseconds / 3600000;
        miliseconds %= 3600000;
        time_shift[1] = miliseconds / 60000;
        miliseconds %= 60000;
        time_shift[2] = miliseconds / 1000;
        miliseconds %= 1000;
        time_shift[3] = miliseconds;

        for(int j = 0; j < 4; j++) {
            if(j != 0) (*out) << separators[j];
            if(j == 3 && time_shift[j] < 100) (*out) << '0';
            if(time_shift[j] < 10) {
                (*out) << '0';
                (*out) << time_shift[j];
            }
            else (*out) << time_shift[j];
        }
    }
}