//
// Created by albert on 01.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>

using ::std::string;

namespace academia {
    class TeacherId {
    private:
        int id;
        friend bool operator!=(const TeacherId &a, const TeacherId &b);
        friend bool operator==(const TeacherId &a, const TeacherId &b);
    public:
        TeacherId();
        TeacherId(int id);
        operator int();
    };

    class Teacher {
    private:
        TeacherId teacher_id;
        string name;
        string department;
        friend bool operator!=(const Teacher &a, const Teacher &b);
        friend bool operator==(const Teacher &a, const Teacher &b);
    public:
        Teacher();
        Teacher(TeacherId teacher_id, string name, string department);
        TeacherId Id() const;
        string Name() const;
        string Department() const;
    };

    class TeacherHash {
    public:
        TeacherHash() = default;
        size_t operator()(const Teacher &teacher) const;
    };
}
#endif //JIMP_EXERCISES_TEACHERHASH_H
