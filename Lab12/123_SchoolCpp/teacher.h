#pragma once

#include "human.h"
#include <string>

class teacher :
    public human
{
public:
    teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time)
        : human(std::move(last_name), std::move(name), std::move(second_name)) , work_time_(work_time) {
    }

    // return teaching load in hours
    unsigned int get_work_time() const {
        return work_time_;
    }

private:
    unsigned int work_time_{ 0 }; // teaching hours per semester
};

