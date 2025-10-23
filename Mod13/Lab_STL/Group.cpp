#include <iostream>
#include <string>
#include <Windows.h>
#include "Group.h"
#include "Student.h"


using namespace std;


	Group::Group(string name)
	{
		this->name = name;
	}
		Group::Group()
	{
		name = "Не определена";
	}
	void Group::setName(string newName)
	{
        name = newName;
    }

	string Group::getName()
	{
        return name;
	}








