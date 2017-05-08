//
// Created by albert on 02.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include <sstream>

using ::std::stringstream;
using ::std::string;
using ::std::invalid_argument;

namespace moviesubs{
    class MissingTimeSpecification {};
    class OutOfOrderFrames {};
    class NegativeFrameAfterShift {};
    class InvalidSubtitleLineFormat {};
    class SubtitleEndBeforeStart {
    private:
        int exception_line_number;
        string exception_line_string;
    public:
        SubtitleEndBeforeStart(int line_number, string line_string);
        int LineAt() const;
        string what() const;
    };

    class MovieSubtitles {
    public:
        MovieSubtitles() = default;
        virtual void ShiftAllSubtitlesBy(int, int fps, std::stringstream *in, std::stringstream *out) = 0;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() = default;
        virtual void ShiftAllSubtitlesBy(int, int fps, stringstream *in, stringstream *out) throw
        (NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat, invalid_argument);
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles() = default;
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) throw
        (NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat, OutOfOrderFrames, invalid_argument);
    };

    //used by SubRipSubtitles::ShiftAllSubtitlesBy
    void print_time(int miliseconds, char separators[], std::stringstream *out);
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
