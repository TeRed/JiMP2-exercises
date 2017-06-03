//
// Created by albert on 01.06.17.
//

#include "TeacherHash.h"
#include <functional>

using ::std::string;

namespace academia {
    TeacherId::TeacherId() {
        id = -1;
    }

    TeacherId::TeacherId(int id) {
        this->id = id;
    }

    TeacherId::operator int() {
        return id;
    }

    bool operator!=(const TeacherId &a, const TeacherId &b) {
        return (a.id != b.id);
    }

    bool operator==(const TeacherId &a, const TeacherId &b) {
        return (a.id == b.id);
    }

    bool operator!=(const Teacher &a, const Teacher &b) {
        return (a.teacher_id != b.teacher_id && a.name != b.name && a.department != b.department);
    }

    bool operator==(const Teacher &a, const Teacher &b) {
        return (a.teacher_id == b.teacher_id && a.name == b.name && a.department == b.department);
    }

    Teacher::Teacher() : teacher_id() {
        name = "";
        department = "";
    }

    Teacher::Teacher(TeacherId teacher_id, string name, string department) : teacher_id(teacher_id) {
        this->name = name;
        this->department = department;
    }

    TeacherId Teacher::Id() const {
        return teacher_id;
    }

    string Teacher::Name() const {
        return name;
    }

    string Teacher::Department() const {
        return department;
    }

    size_t TeacherHash::operator()(const Teacher &teacher) const {
        std::hash<string> hashString;
        std::hash<int> hashInt;

        return hashInt(teacher.Id())*hashString(teacher.Name())*7 + hashString(teacher.Department())*17;
    }
}