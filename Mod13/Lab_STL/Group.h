#pragma once /* ������ �� �������� ����������� ������������� ����� */
#include <string>
#include "Student.h"

using namespace std;

class Group
{
private:
	string name;
	

public:
	Group(string name);
	Group();

	void setName(string newName);
	string getName();
};