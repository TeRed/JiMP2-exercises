//
// Created by albert on 11.04.17.
//

#include "StudentRepository.h"

using ::academia::Student;
using ::academia::StudyYear;
using ::academia::StudentRepository;

StudyYear::operator int() const {
    return study_year;
}
Student::Student(): year(0) {
    id = first_name = last_name = program = "";
}
Student::Student(string id, string first_name, string last_name, string program, int year): year(year) {
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->program = program;
}
string Student::Id() const{
    return id;
}
string Student::FirstName() {
    return first_name;
}
string Student::LastName(){
    return last_name;
}
string Student::Program() {
    return program;
}
StudyYear Student::Year() {
    return year;
}
void Student::ChangeLastName(string last_name) {
    this->last_name = last_name;
}
StudentRepository::StudentRepository(initializer_list<Student> initializer_list){
    for(auto it = initializer_list.begin(); it != initializer_list.end(); ++it) {
        student_list.push_back(*it);
    }
}
size_t StudentRepository::StudentCount() const {
    return student_list.size();
}
Student & StudentRepository::operator[](string id){
    for(auto it = student_list.begin(); it != student_list.end(); ++it) {
        if((*it).Id() == id) return (*it);
    }
}
bool ::academia::operator==(const StudyYear & a, const StudyYear & b) {
    return (a.study_year == b.study_year);
}
bool ::academia::operator<(const StudyYear & a, const StudyYear & b) {
    return (a.study_year < b.study_year);
}
bool ::academia::operator==(const Student & a, const Student & b) {
    if(a.id != b.id || a.program != b.program) return false;
    if(a.first_name != b.first_name || a.last_name != b.last_name) return false;

    return (a.year == b.year);
}
bool ::academia::operator==(const StudentRepository & a, const StudentRepository & b) {
    if(a.student_list.size() != b.student_list.size()) return false;
    for(int i = 0; i < a.student_list.size(); i++) {
        int j = 0;
        for(j = 0; j < b.student_list.size(); j++) {
            if(a.student_list[i] == b.student_list[j]) break;
        }
        if(j == b.student_list.size()) return false;
    }
     return true;
}