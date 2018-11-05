//
// Created by albert on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

using std::string;

namespace nets{
    class JsonValue{
    public:
        JsonValue(double value);
        JsonValue(int value);
        JsonValue(string value);
        JsonValue(bool value);
        JsonValue(std::vector<JsonValue> value);
        JsonValue(std::map<string, JsonValue> value);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        std::experimental::optional<double> doubleVal;
        std::experimental::optional<int> intVal;
        std::experimental::optional<string> stringVal;
        std::experimental::optional<bool> boolVal;
        std::experimental::optional<std::vector<JsonValue>> vectorVal;
        std::experimental::optional<std::map<string, JsonValue>> mapVal;

        void push_invisible_backslashes(string &str) const;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
