//
// Created by przemek on 06.04.17.
//

#include <iostream>
#include "WordCounter.h"

using ::std::ifstream;


namespace datastructures{
    Word::Word(){
        word = "";
    }
    Word::Word(string str) {
        word = str;
    }
    string Word::get_word() const {
        return word;
    }
    Counts::Counts() {
        counts = 1;
    }
    Counts::Counts(int x) {
        counts = x;
    }
    int Counts::get_counts() const{
        return counts;
    }

    Counts& Counts::operator++(){
        counts++;
        return *this;
    }

    Counts Counts::operator++(int){
        Counts tmp(*this);
        operator++();
        return tmp;
    }

    WordCounter::WordCounter(string path){
        ifstream in(path);
        string word;
        while(in >> word){
            alone_word(word);
            if(word == "") continue;
            list <pair<Counts, Word>>::iterator it;
            for(it = word_list.begin(); it != word_list.end(); ++it){
                if((*it).second.get_word() == word){
                    ((*it).first)++;
                    break;
                }
            }
            if(it == word_list.end()){
                word_list.push_back({Counts(), Word(word)});
            }
        }
        in.close();
    }

    WordCounter::WordCounter(initializer_list<Word> initializer_list){
//        initializer_list <Word>::iterator initializer_list_it;
        list <pair<Counts, Word>>::iterator word_list_it;

        for(auto initializer_list_it = initializer_list.begin(); initializer_list_it != initializer_list.end(); ++initializer_list_it){
            for(word_list_it = word_list.begin(); word_list_it != word_list.end(); ++word_list_it){
                if((*word_list_it).second == (*initializer_list_it)){
                    (*word_list_it).first++;
                    break;
                }
            }
            if(word_list_it == word_list.end()){
                word_list.push_back({Counts(), (*initializer_list_it)});
            }
        }
    }

    int WordCounter::operator[](string word) {
        list <pair<Counts, Word>>::iterator it;
        for(it = word_list.begin(); it != word_list.end(); ++it){
            if((*it).second.get_word() == word) return (*it).first.get_counts();
        }
        return 0;
    }

    void WordCounter::sort_desc(){
        word_list.sort();
        word_list.reverse();
    }


    int WordCounter::DistinctWords() const {
        return word_list.size();
    }

    int WordCounter::TotalWords() {
        int total = 0;
        list <pair<Counts, Word>>::iterator it;

        for(it = word_list.begin(); it != word_list.end(); ++it){
            total += (*it).first.get_counts();
        }

        return total;
    }

    set<Word> WordCounter::Words() {
        set<Word> to_return;
        list <pair<Counts, Word>>::iterator it;

        for(it = word_list.begin(); it != word_list.end(); ++it){
            to_return.insert((*it).second);
        }

        return to_return;
    }

    void alone_word(string &word){
        for(int i = 0; i < word.size(); i++){
            if(!isalpha(word[i])){
                word.erase(i--, 1);
            }
        }
    }

    ostream& operator<<(ostream& output, WordCounter& word){
        word.sort_desc();

        list <pair<Counts, Word>>::iterator it;
        for(it = word.word_list.begin(); it != word.word_list.end(); ++it){
            output << (*it).second.get_word() << " " << (*it).first.get_counts() << std::endl;
        }
        return output;
    }

    bool operator<(const Word& wrd1, const Word& wrd2){
        return (wrd1.get_word() < wrd2.get_word());
    }

    bool operator>(const Word& wrd1, const Word& wrd2){
        return (wrd1.get_word() > wrd2.get_word());
    }

    bool operator==(const Word& wrd1, const Word& wrd2){
        return (wrd1.get_word() == wrd2.get_word());
    }

    bool operator<(const Counts& cnt1, const Counts& cnt2){
        return (cnt1.get_counts() < cnt2.get_counts());
    }

    bool operator>(const Counts& cnt1, const Counts& cnt2){
        return (cnt1.get_counts() > cnt2.get_counts());
    }

    bool operator==(const Counts& cnt1, const Counts& cnt2){
        return (cnt1.get_counts() == cnt2.get_counts());
    }
}