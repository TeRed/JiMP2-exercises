//
// Created by albert on 24.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>

namespace nets{
    class View{
    public:
        View(std::string szablon);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    private:
        std::string given_template;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
