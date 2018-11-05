//
// Created by albert on 18.03.17.
//

#include <iostream>
#include "TinyUrl.h"

namespace tinyurl{
    std::unique_ptr<TinyUrlCodec> Init(){
        auto p = std::make_unique<TinyUrlCodec> ();
        p->state.fill('z');
        return p;
    }

    void NextHash(std::array<char, 6> *state){
        (*state)[5]++;
        if((*state)[5] == '9'+1){
            (*state)[5] = 'A';
            return;
        }
        else if((*state)[5] == 'Z'+1){
            (*state)[5] = 'a';
            return;
        }
        else if((*state)[5] == 'z'+1){
            (*state)[5] = '0';
            (*state)[4]++;
        }
        else return;

        for(int i = 4; i >= 0; i--){
            if((*state)[i] == '9'+1){
                (*state)[i] = 'A';
                return;
            }
            else if((*state)[i] == 'Z'+1){
                (*state)[i] = 'a';
                return;
            }
            else if((*state)[i] == 'z'+1){
                if(i == 0){
                    (*state).fill('0');
                    return;
                }
                (*state)[i-1]++;
                (*state)[i] = '0';
            }
            else return;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string shortURL = "";
        std::string to_translate = "";
        std::string translated = "";
        int slash_count = 0;
        for(int i = 0; i < url.length(); i++){
            if(slash_count < 3) shortURL += url[i];
            else to_translate += url[i];
            if(url[i] == '/') slash_count++;
        }
        if(to_translate == ""){
            (*codec)->hash.emplace("", "");
            return shortURL;
        }

        NextHash(&((*codec)->state));
        for(auto &v : (*codec)->state) translated += v;
        (*codec)->hash.emplace(to_translate, translated);
        shortURL += translated;
        return shortURL;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::string normalURL = "";
        std::string to_translate = "";
        std::string translated = "";
        int slash_count = 0;
        for(int i = 0; i < hash.length(); i++){
            if(slash_count < 3) normalURL += hash[i];
            else to_translate += hash[i];
            if(hash[i] == '/') slash_count++;
        }
        for(auto &v : codec->hash){
            if(v.second == to_translate){
                normalURL += v.first;
                return normalURL;
            }
        }
    }
}