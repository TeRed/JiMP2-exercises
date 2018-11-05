//
// Created by albert on 24.03.17.
//

#include "SimpleTemplateEngine.h"
namespace nets{
    View::View(std::string given_template) {
        this->given_template = given_template;
    }

    View::~View() {}

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string replaced = ""; //zwracany szablon po prztełumaczeniu
        std::string pattern = ""; //wzór do zamiany
        int left_bracket_count = 0; //zlicza '{'
        int right_bracket_count = 0; // zlicza '}'

        for(int i = 0; i < given_template.length(); i++){ //główna pętla przechodzi po całym szablonie do przetłuamczenia
            if(given_template[i] != '{') replaced += given_template[i];
            else{ //gdy możliwe że trafiliśmy na wzorzec do zmiany
                while(given_template[i] == '{'){
                    left_bracket_count++;
                    i++;
                }
                while(given_template[i] != '}' && given_template[i] != ' '){
                    pattern += given_template[i];
                    i++;
                }
                while(given_template[i] == '}'){
                    right_bracket_count++;
                    i++;
                }
                if(left_bracket_count >= 2 && right_bracket_count >= 2){
                    for(int j = 0; j < left_bracket_count-2; j++) replaced += '{';
                    std::unordered_map<std::string, std::string>::const_iterator got = model.find(pattern);
                    if(got != model.end()) replaced += got->second;
                    for(int j = 0; j < right_bracket_count-2; j++) replaced += '}';
                }
                else{
                    for(int j = 0; j < left_bracket_count; j++) replaced += '{';
                    replaced += pattern;
                    for(int j = 0; j < right_bracket_count; j++) replaced += '}';
                }
                pattern = "";
                left_bracket_count = right_bracket_count = 0;
                i--; //żeby możliwe było dodanie do 'replaced' pierwszego znaku niepasującego do wzorca
            }
        }

        return replaced;
    }
}