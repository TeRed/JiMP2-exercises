//
// Created by duzalber on 14.03.17.
//

#include "MinimalTimeDifference.h"
#include <climits>

namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {
        int colon_position = -1;
        unsigned int minutes = 0;
        for (int i = 0; i < time_HH_MM.size(); i++) {
            if (time_HH_MM[i] == ':') {
                colon_position = i;
                break;
            }
        }
        std::string number = "";
        for (int i = 0; i < colon_position; i++) {
            number += time_HH_MM[i];
        }
        minutes += stoul(number) * 60;
        number = "";
        for (int i = colon_position + 1; i < time_HH_MM.size(); i++) {
            number += time_HH_MM[i];
        }
        minutes += stoul(number);

        return minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        std::vector<unsigned int> times_minutes;

        for (std::string v : times) {
            times_minutes.push_back(ToMinutes(v));
        }

        unsigned int min_diff = UINT_MAX;

        for (int i = 0; i < times_minutes.size(); i++)
            for (int j = i + 1; j < times_minutes.size(); j++) {
                if (abs(times_minutes[i] - times_minutes[j]) < min_diff)
                    min_diff = abs(times_minutes[i] - times_minutes[j]);
                if(std::min(times_minutes[i], times_minutes[j]) + (24*60 - std::max(times_minutes[i], times_minutes[j])) < min_diff)
                    min_diff = std::min(times_minutes[i], times_minutes[j]) + (24*60 - std::max(times_minutes[i], times_minutes[j]));
            }
        return min_diff;
    }
}