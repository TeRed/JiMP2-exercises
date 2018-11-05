//
// Created by duzalber on 14.03.17.
//

#include "CCounter.h"

namespace ccounter{
    std::unique_ptr<Counter> Init(){
        auto p = std::make_unique<Counter> ();
        return p;
    }

    void Inc(std::string key, std::unique_ptr<Counter>* counter){
        for(auto &v : (*counter)->values){
            if(v.first == key){
                v.second++;
                return;
            }
        }
        (*counter)->values.emplace(key, 1);
        return;
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key){
        for(auto &v : counter->values){
            if(v.first == key) return v.second;
        }
        return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter){
        for(auto &v : (*counter)->values){
            if(v.first == key){
                v.second = value;
                return;
            }
        }
        (*counter)->values.emplace(key, value);
        return;
    }
}
