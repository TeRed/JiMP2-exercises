//
// Created by albert on 30.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

using ::std::string;
using ::std::set;
using ::std::experimental::string_view;
using ::std::initializer_list;

namespace pool{
    class TextPool{
    private:
        set<string_view> strings;
    public:
//        Constructors
        TextPool() = default; //empty should be inline?
        TextPool(initializer_list<string_view>);

//        Copy
        TextPool(const TextPool &) = delete;
        TextPool &operator=(const TextPool &) = delete;

//        Move
        TextPool(TextPool &&);
        TextPool &operator=(TextPool &&);

//        Destructor
        ~TextPool() = default;

//        Methods
        string_view Intern(const string &str);
        size_t StoredStringCount() const;
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
