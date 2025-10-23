#pragma once

#include <string>
#include <list>
#include <algorithm>
#include "Student.h"

class Group
{
private:
    std::string name;

    std::list<Student> masSt;
    std::list<Student>::iterator iter;

public:
    Group(std::string name);
    Group();

    void setName(std::string newName);
    std::string getName();

    int getSize();
    void addStudent(Student newStudent);
    void delStudent(const Student& oldStudent);
    Student findStudent(std::string firstName, std::string lastName);
    void GroupSort();
    void GroupOut();
};

