#pragma once

#include <string>
#include "IdCard.h"

class Student
{
public:
    // Constructor 
    //Student(std::string name, std::string last_name, IdCard* id);

    // ctor for composition
    Student(std::string name, std::string last_name, int id, std::string cat);

    void set_name(const std::string& student_name);
    std::string get_name() const;

    void set_last_name(const std::string& student_last_name);
    std::string get_last_name() const;

    void set_scores(const int student_scores[5]);

    void set_average_score(double avg);
    double get_average_score() const;

    void calculate_average_score();

    //void set_id_card(IdCard* c);
    //IdCard get_id_card() const;
    void set_id_card(int id, std::string c);
    int  get_id_card() const;
    
    // Print Student info
    void display() const;                  


    // Save student data to file
    void save();

    // RAII: Destructor
    ~Student();

private:
    int scores[5]{};
    double average_score{};
    std::string name;
    std::string last_name;

    //IdCard* iCard = nullptr;
    IdCard iCard;
};

