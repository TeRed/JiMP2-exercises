//
// Created by albert on 23.05.17.
//

#include "Algo.h"
#include <algorithm>

namespace algo {
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(v.begin(), v.end(), element) != v.end();
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> v(length, initial_value);

        return v;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        /*std::vector<std::string> vector_with_string;

        std::for_each(v.begin(), v.end(), move(vector_with_string));

        return vector_with_string;*/
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> s;

        std::for_each(m.begin(), m.end(), [&s](std::pair<std::string, int> p) { s.emplace(p.first); });

        return s;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> v;

        std::for_each(m.begin(), m.end(), [&v](std::pair<std::string, int> p) { v.push_back(p.second); });

        return v;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        std::set<std::string> set = Keys(v);
        return std::find(set.begin(), set.end(), key) != set.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> vector = Values(v);
        return std::find(vector.begin(), vector.end(), value) != vector.end();
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor) {
        std::map<std::string, int> map;
        std::for_each(m.begin(), m.end(), [&map](std::pair<std::string, int> p) { map.emplace(std::pair<std::string, int> {p.first, p.second /= divisor}); });

        return map;
    }
}