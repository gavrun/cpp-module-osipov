#pragma once

#include "human.h"

class teacher 
    : public human {
public:
    teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time)
        : human(std::move(last_name), std::move(name), std::move(second_name)), work_time_(work_time) {
    }

    unsigned int get_work_time() const { return work_time_; }

    // polymorphic
    const char* role() const override { return "teacher"; }

    void print(std::ostream& os) const override {
        os << get_full_name() << " | role: " << role()
            << " | workload (hours/semester) = " << get_work_time();
    }

private:
    unsigned int work_time_{ 0 };
};

