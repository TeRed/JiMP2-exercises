//
// Created by albert on 30.03.17.
//
#include "TextPool.h"

namespace pool{
    TextPool::TextPool(initializer_list<string_view> string_list){
        for(initializer_list<string_view>::iterator it = string_list.begin(); it != string_list.end(); it++){
            strings.insert(*it);
        }
    }

    TextPool::TextPool(TextPool &&textpool){
        strings.clear();
        strings.swap(textpool.strings);
    }

    TextPool & TextPool::operator=(TextPool &&textpool){
        if(this == &textpool) return *this;
        strings.clear();
        strings.swap(textpool.strings);
        return (*this);
    }

    string_view TextPool::Intern(const string &str){
        string_view handle(str);
        set<string_view>::iterator result;
        result = strings.find(handle);
        if(result != strings.end()){
            return *result;
        }
        strings.insert(string_view(str));

        return handle;
    }

    size_t TextPool::StoredStringCount() const {
        return strings.size();
    }
}