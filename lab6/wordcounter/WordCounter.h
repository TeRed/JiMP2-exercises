//
// Created by przemek on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <set>
#include <initializer_list>

using ::std::string;
using ::std::list;
using ::std::pair;
using ::std::ostream;
using ::std::initializer_list;
using ::std::set;

namespace datastructures{
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
        Counts(int);
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
        WordCounter(initializer_list<Word> initializer_list);
        int operator[](string);
        void sort_desc();
        int DistinctWords() const;
        int TotalWords(); //const?
        set<Word> Words();
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

#endif //JIMP_EXERCISES_WORDCOUNTER_H
