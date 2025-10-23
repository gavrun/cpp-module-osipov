#pragma once

#include <string>

class IdCard
{
private:
	int number;
	std::string category;

public:
	IdCard();
	IdCard(int);
	IdCard(int, std::string);

	void setNumber(int newNumber);
	int getNumber();
	void setCategory(std::string cat);
	std::string getCategory();
};

