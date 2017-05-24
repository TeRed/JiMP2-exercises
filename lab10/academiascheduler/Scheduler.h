//
// Created by albert on 22.05.17.
//

#ifndef JIMP_EXERCISES_SHEDULER_H
#define JIMP_EXERCISES_SHEDULER_H
#include <vector>
#include <map>
#include <set>

using ::std::vector;
using ::std::map;
using ::std::set;
using ::std::size_t;

namespace academia {

    class NoViableSolutionFound {};

    class SchedulingItem {
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    public:
        SchedulingItem(){};
        SchedulingItem(int, int, int, int, int);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    };

    class Schedule {
    private:
        vector <SchedulingItem> SchedulingItemVector;
    public:
        Schedule(){};
        ~Schedule(){};
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        void InsertScheduleItem(const SchedulingItem &item);
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        size_t Size() const;
        SchedulingItem operator[] (int index) const;
    };

    class Scheduler {
    public:
        Scheduler(){};
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
        virtual ~Scheduler(){};
    };

    class GreedyScheduler : public Scheduler {
    private:
        bool checkAvailability(const std::vector<int> &slots, int slot) const;
    public:
        GreedyScheduler(){};
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };
}
#endif //JIMP_EXERCISES_SHEDULER_H