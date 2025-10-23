#pragma once

#include "Student.h"
#include <string>
#include <list>
#include <algorithm>
#include <set>

class Group
{
private:
    std::string name;

    //std::list<Student> masSt;
    //std::list<Student>::iterator iter;

    std::multiset<Student*, compareStudent> masSt;
    std::multiset<Student*, compareStudent>::iterator iter;

public:
    Group(std::string name);
    Group();

    void setName(std::string newName);
    std::string getName();

    int getSize();

    //void addStudent(Student newStudent);
    void addStudent(Student* newStudent);

    //void delStudent(const Student& oldStudent);
    void delStudent(Student* oldStudent);

    //Student findStudent(std::string firstName, std::string lastName);
    Student* findStudent(std::string firstName, std::string lastName);

    //void GroupSort();

    void GroupOut();
};

