//
// Created by albert on 27.03.17.
//

#include "SimpleJson.h"

namespace nets{
    JsonValue::JsonValue(double value){
        doubleVal = value;
    }
    JsonValue::JsonValue(int value){
        intVal = value;
    }
    JsonValue::JsonValue(string value){
        push_invisible_backslashes(value);
        stringVal = value;
    }
    JsonValue::JsonValue(bool value){
        boolVal = value;
    }
    JsonValue::JsonValue(std::vector<JsonValue> value){
        vectorVal = value;
    }
    JsonValue::JsonValue(std::map<string, JsonValue> value){
        mapVal = value;
    }

    JsonValue::~JsonValue(){}

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        std::experimental::optional<JsonValue> to_return;
        for(auto n : *mapVal){
            if(n.first == name) to_return = n.second;
        }
        return to_return;
    }

    std::string JsonValue::ToString() const{
        if(doubleVal){
            string str = std::to_string(*doubleVal);
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);
            return str;
        }
        if(intVal){
            return std::to_string(*intVal);
        }
        if(stringVal){
            return ("\"" + *stringVal + "\"");
        }
        if(boolVal){
            return (*boolVal ? "true" : "false");
        }
        if(vectorVal){
            string to_return = "[";
            bool not_beginning = false;

            for(auto n : *vectorVal){
                if(not_beginning) to_return += ", ";
                to_return += n.ToString();
                not_beginning = true;
            }
            to_return += "]";
            return to_return;
        }
        if(mapVal){
            string to_return = "{";
            bool not_beginning = false;

            for(auto n : *mapVal){
                string tmp = n.first;
                push_invisible_backslashes(tmp);
                if(not_beginning) to_return += ", ";
                not_beginning = true;
                to_return += ("\"" + tmp + "\": " + n.second.ToString());
            }
            to_return += "}";
            return to_return;
        }
    }

    void JsonValue::push_invisible_backslashes(string &str) const{
        for(int i = 0; i < str.length(); i++){
            if((str)[i] == '\"' || (str)[i] == '\\'){
                str.insert(i, 1, '\\');
                i++;
            }
        }
    }
}