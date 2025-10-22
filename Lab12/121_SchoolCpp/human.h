#pragma once

#include <string>
#include <sstream>

class human
{
public:
    // value constructor
    human(std::string last_name, std::string name, std::string father_name)
        : last_name_(std::move(last_name)), name_(std::move(name)), father_name_(std::move(father_name)) {
    }

    // build "Lastname Name Secondname"
    std::string get_full_name() const {
        std::ostringstream full_name;
        full_name << last_name_ << ' ' << name_ << ' ' << father_name_;

        return full_name.str();
    }

private:
    std::string name_;
    std::string last_name_;
    std::string father_name_;
};

