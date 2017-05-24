//
// Created by albert on 22.05.17.
//

#include <iostream>
#include "Scheduler.h"
#include <algorithm>
#include <iterator>

namespace academia {
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        this->course_id = course_id;
        this->teacher_id = teacher_id;
        this->room_id = room_id;
        this->time_slot = time_slot;
        this->year = year;
    }

    int SchedulingItem::CourseId() const {
        return course_id;
    }
    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }
    int SchedulingItem::RoomId() const {
        return room_id;
    }
    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }
    int SchedulingItem::Year() const {
        return year;
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule schedule;

        for(auto it : SchedulingItemVector) {
            if(it.TeacherId() == teacher_id) schedule.InsertScheduleItem(it);
        }

        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule schedule;

        for(auto it : SchedulingItemVector) {
            if(it.RoomId() == room_id) schedule.InsertScheduleItem(it);
        }

        return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule schedule;

        for(auto it : SchedulingItemVector) {
            if(it.Year() == year) schedule.InsertScheduleItem(it);
        }

        return schedule;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        SchedulingItemVector.push_back(item);
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        vector<int> availableTimeSlots;

        for(int slot = 1; slot <= n_time_slots; slot++) {
            bool free_slot = true;
            for(auto it : SchedulingItemVector) {
                if(it.TimeSlot() == slot) free_slot = false;
            }
            if(free_slot) availableTimeSlots.push_back(slot);
        }

        return availableTimeSlots;
    }

    size_t Schedule::Size() const {
        return SchedulingItemVector.size();
    }

    SchedulingItem Schedule::operator[](int i) const {
        return SchedulingItemVector[i];
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {};

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {

        Schedule schedule;

        for (auto &teacher : teacher_courses_assignment) {
            for (auto &course : teacher.second) {
                bool used_teacher = false;
                for (auto &year : courses_of_year) {
                    if(used_teacher) break;
                    if (std::find(year.second.begin(), year.second.end(), course) != year.second.end()) {
                        for(auto &room : rooms) {
                            if(used_teacher) break;
                            for (int slot = 1; slot <= n_time_slots; slot++) {
                                if(used_teacher) break;
                                if(!checkAvailability(schedule.OfTeacher(teacher.first).AvailableTimeSlots(n_time_slots), slot)) continue;
                                if(!checkAvailability(schedule.OfYear(year.first).AvailableTimeSlots(n_time_slots), slot)) continue;
                                if(!checkAvailability(schedule.OfRoom(room).AvailableTimeSlots(n_time_slots), slot)) continue;
                                schedule.InsertScheduleItem(SchedulingItem{course, teacher.first, room, slot, year.first});
                                used_teacher = true;
                            }
                        }
                    }
                }
                if(!used_teacher) throw NoViableSolutionFound();
            }
        }

        return schedule;
    }

    bool GreedyScheduler::checkAvailability(const std::vector<int> &slots, int slot) const {
        return std::find(slots.begin(), slots.end(), slot) != slots.end();
    }
}