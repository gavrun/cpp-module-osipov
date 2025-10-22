#pragma once

#include <string>
#include <sstream>
#include <ostream>

class human
{
public:
    human(std::string last_name, std::string name, std::string father_name)
        : last_name_(std::move(last_name)), name_(std::move(name)), father_name_(std::move(father_name)) {
    }

    virtual ~human() = default;

    std::string get_full_name() const {
        std::ostringstream full_name;
        full_name << last_name_ << ' ' << name_ << ' ' << father_name_;
        return full_name.str();
    }

    // polymorphic interface
    virtual const char* role() const = 0;
    virtual void print(std::ostream& os) const = 0;

protected:
    const std::string& name()  const { return name_; }
    const std::string& lname() const { return last_name_; }
    const std::string& fname() const { return father_name_; }

private:
    std::string name_;
    std::string last_name_;
    std::string father_name_;
};

