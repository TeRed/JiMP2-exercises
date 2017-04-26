//
// Created by albert on 11.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <string>
#include <vector>
#include <initializer_list>
#include <unordered_set>

using ::std::string;
using ::std::vector;
using ::std::initializer_list;

namespace academia{
    class StudyYear{
    private:
        int study_year;
    public:
        StudyYear() {study_year = 1;};
        StudyYear(int study_year) { this->study_year = study_year; };
        operator int() const;
        friend bool operator==(const StudyYear &, const StudyYear &);
        friend bool operator<(const StudyYear &, const StudyYear &);
    };

    class Student{
    private:
        string id, first_name, last_name, program;
        StudyYear year;
    public:
        Student();
        Student(string id, string first_name, string last_name, string program, int year);
        string Id() const;
        string FirstName();
        string LastName();
        string Program();
        StudyYear Year();
        void ChangeLastName(string last_name);
        friend bool operator==(const Student &, const Student &);
    };

    class StudentRepository{
    private:
        vector<Student> student_list;
    public:
        StudentRepository(){};
        StudentRepository(initializer_list<Student> initializer_list);
        ~StudentRepository(){};
        size_t StudentCount() const;
        Student & operator[](string);
        friend bool operator==(const StudentRepository &, const StudentRepository &);
    };

    bool operator==(const StudyYear & a, const StudyYear & b);
    bool operator<(const StudyYear & a, const StudyYear & b);
    bool operator==(const Student & a, const Student & b);
    bool operator==(const StudentRepository & a, const StudentRepository & b);
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
