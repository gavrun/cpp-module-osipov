#pragma once

#include <string>

class Student
{
public:
    // Constructor 
    Student(std::string name, std::string last_name);

    void set_name(const std::string& student_name);

    std::string get_name() const;

    void set_last_name(const std::string& student_last_name);

    std::string get_last_name() const;

    void set_scores(const int student_scores[5]);

    void set_average_score(double avg);

    double get_average_score() const;

    void calculate_average_score();

private:
    int scores[5]{};
    double average_score{};
    std::string name;
    std::string last_name;
};

