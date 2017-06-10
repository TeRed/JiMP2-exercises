//
// Created by przemek on 10.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class id_T, class simple_T>
    class   SequentialIdGenerator{
    public:
        SequentialIdGenerator(const simple_T counter = simple_T()){
            this->counter = counter;
        }
        id_T NextValue(){
            id_T id = id_T(counter);
            ++counter;
            return id;
        }

    private:
        simple_T counter;
    };