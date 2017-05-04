//
// Created by albert on 02.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>

using ::std::stringstream;
using ::std::string;

namespace moviesubs {
    class NegativeFrameAfterShift {};
    class InvalidSubtitleLineFormat {};
    class SubtitleEndBeforeStart {
    private:
        int at_line;
        string what_line;
    public:
        SubtitleEndBeforeStart();
        int LineAt() const;
        string what() const;
        void inc();
        void set_what(string what);
    };

    class MicroDvdSubtitles{
    public:
        MicroDvdSubtitles(){};
        void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) throw
        (NegativeFrameAfterShift, SubtitleEndBeforeStart, InvalidSubtitleLineFormat);
    };
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
