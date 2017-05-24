//
// Created by albert on 23.05.17.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H
#include <vector>
#include <string>
#include <map>
#include <set>

namespace algo {
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);

    bool Contains(const std::vector<int> &v, int element);

    void InitializeWith(int initial_value, std::vector<int> *v);
    std::vector<int> InitializedVectorOfLength(int length, int initial_value);
    std::vector<std::string> MapToString(const std::vector<double> &v);

    std::set<std::string> Keys(const std::map<std::string, int> &m);
    std::vector<int> Values(const std::map<std::string, int> &m);
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);
    bool ContainsValue(const std::map<std::string, int> &v, int value);

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor);
}
#endif //JIMP_EXERCISES_ALGO_H
