//
// Created by albert on 01.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling {
    std::chrono::high_resolution_clock::time_point Now() {
        return std::chrono::high_resolution_clock::now();
    }

    double ToMiliseconds(std::chrono::high_resolution_clock::duration span) {
        return std::chrono::duration_cast<std::chrono::duration<double>>(span).count() * 1000;
    }

    template<class T>
    auto TimeRecorder(T object) {
        auto before = Now();
        auto returned_value = object();
        auto after = Now();
        return std::make_pair(returned_value, ToMiliseconds(after-before));
    }
}
#endif //JIMP_EXERCISES_TIMERECORDER_H
