//
// Created by przemek on 06.04.17.
//

#ifndef JIMP_EXERCISES_COUNTER_H
#define JIMP_EXERCISES_COUNTER_H

#include <string>
#include <list>
#include <fstream>
#include <iomanip>

using ::std::string;
using ::std::list;
using ::std::pair;
using ::std::ostream;

namespace abc{
    class Word{
    private:
        string word;
    public:
        Word();
        Word(string str);
        ~Word(){};
        string get_word() const;
    };

    class Counts{
    private:
        int counts;
    public:
        Counts();
        ~Counts(){};
        int get_counts() const;

        Counts& operator++();
        Counts operator++(int);
    };

    class WordCounter{
    private:
        list <pair<Counts, Word>> word_list;
        friend ostream& operator<<(ostream& output, WordCounter& word);
    public:
        WordCounter(){};
        ~WordCounter(){};
        WordCounter(string path);
        int operator[](string);
        void sort_desc();
    };

    void alone_word(string &word);
    ostream& operator<<(ostream& output, WordCounter& word);
    bool operator<(const Word& wrd1, const Word& wrd2);
    bool operator>(const Word& wrd1, const Word& wrd2);
    bool operator==(const Word& wrd1, const Word& wrd2);
    bool operator<(const Counts& cnt1, const Counts& cnt2);
    bool operator>(const Counts& cnt1, const Counts& cnt2);
    bool operator==(const Counts& cnt1, const Counts& cnt2);
}

#endif //JIMP_EXERCISES_COUNTER_H
