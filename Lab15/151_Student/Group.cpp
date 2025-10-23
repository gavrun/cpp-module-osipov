#include "Group.h"
#include <iostream>

Group::Group(std::string name) : name(name) {}
Group::Group() : name("Not defined") {}

void Group::setName(std::string newName) { name = newName; }
std::string Group::getName() { return name; }

int Group::getSize() {
    return static_cast<int>(masSt.size());
}

void Group::addStudent(Student newStudent) {
    masSt.push_back(std::move(newStudent));
}

void Group::delStudent(const Student& oldStudent) {
    masSt.remove(oldStudent);
}

void Group::GroupOut() {
    // iterate over values (not pointers)
    for (iter = masSt.begin(); iter != masSt.end(); ++iter) {
        iter->display();
    }
}

Student Group::findStudent(std::string firstName, std::string lastName) {
    Student probe(firstName, lastName, nullptr); // only for comparison
    auto it = std::find(masSt.begin(), masSt.end(), probe);
    if (it == masSt.end()) {
        return Student();
    }
    return *it;
}

void Group::GroupSort() {
    // sort by operator< from Student
    masSt.sort();
}