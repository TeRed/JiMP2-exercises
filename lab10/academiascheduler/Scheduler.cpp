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

        for(auto it = SchedulingItemVector.begin(); it != SchedulingItemVector.end(); ++it) {
            if((*it).TeacherId() == teacher_id) schedule.InsertScheduleItem(*it);
        }

        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule schedule;

        for(auto it = SchedulingItemVector.begin(); it != SchedulingItemVector.end(); ++it) {
            if((*it).RoomId() == room_id) schedule.InsertScheduleItem(*it);
        }

        return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule schedule;

        for(auto it = SchedulingItemVector.begin(); it != SchedulingItemVector.end(); ++it) {
            if((*it).Year() == year) schedule.InsertScheduleItem(*it);
        }

        return schedule;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        SchedulingItemVector.push_back(item);
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        vector <int> availableTimeSlots;
        bool available[20];

        for(int i = 0; i < 20; i++) available[i] = true;

        for(auto it = SchedulingItemVector.begin(); it != SchedulingItemVector.end(); ++it) {
            available[(*it).TimeSlot()-1] = false;
        }

        for(int i = 0; i < n_time_slots; i++) {
            if(available[i]) availableTimeSlots.push_back(i+1);
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
        /*Schedule schedule;
        int room_counter = 1, slot_counter = 1;
        vector<int> used_teachers;

        for(auto years_it = courses_of_year.begin(); years_it != courses_of_year.end(); ++years_it) {
            for(auto courses_it = (*years_it).second.begin(); courses_it != (*years_it).second.end(); ++courses_it) {

                for(auto teacher_it = teacher_courses_assignment.begin(); teacher_it != teacher_courses_assignment.end(); ++teacher_it) {
                    for(auto t_courses_it = (*teacher_it).second.begin(); t_courses_it != (*teacher_it).second.end(); ++t_courses_it) {

                        if((*courses_it) == (*t_courses_it) && std::find(std::begin(used_teachers), std::end(used_teachers), (*teacher_it).first) == std::end(used_teachers)) {
                            schedule.InsertScheduleItem(SchedulingItem{*courses_it, (*teacher_it).first, room_counter, slot_counter, (*years_it).first});
                            used_teachers.push_back((*teacher_it).first);
                            room_counter++;
                            if(room_counter > rooms.size()){
                                room_counter = 1;
                                slot_counter++;
                                if(slot_counter > n_time_slots) throw NoViableSolutionFound {};
                                used_teachers.clear();
                            }
                        }

                    }
                }

            }
        }*/

        int t_courses = 0;

        for (auto teacher_it = teacher_courses_assignment.begin(); teacher_it != teacher_courses_assignment.end(); ++teacher_it)
            t_courses += (*teacher_it).second.size();

        if(n_time_slots * rooms.size() < t_courses) throw NoViableSolutionFound {};


        Schedule schedule;

        map<int, vector<int>> teachers_copy = teacher_courses_assignment;
        vector<int> rooms_indicator;

        for(int i = 0; i < n_time_slots; i++) rooms_indicator.push_back(0);

        int slot_counter = 1;

        for(auto years_it = courses_of_year.begin(); years_it != courses_of_year.end(); ++years_it) {
            for (auto courses_it = (*years_it).second.begin(); courses_it != (*years_it).second.end(); ++courses_it) {

                for (auto teacher_it = teachers_copy.begin(); teacher_it != teachers_copy.end(); ++teacher_it) {
                    for (auto t_courses_it = (*teacher_it).second.begin(); t_courses_it != (*teacher_it).second.end(); ++t_courses_it) {
                        if((*courses_it) == (*t_courses_it) && (*t_courses_it) != -slot_counter) {
                            schedule.InsertScheduleItem(SchedulingItem{*courses_it, (*teacher_it).first, rooms[rooms_indicator[slot_counter-1]], slot_counter, (*years_it).first});
                            rooms_indicator[slot_counter-1]++;
                            if(rooms_indicator[slot_counter-1] > rooms.size()) throw NoViableSolutionFound {};
                            (*t_courses_it) = -slot_counter;
                            slot_counter++;
                            if(slot_counter > n_time_slots) throw NoViableSolutionFound {};
                        }
                    }
                }
            }
            slot_counter = 1;
        }
        return schedule;
    }
}