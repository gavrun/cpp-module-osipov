#pragma once

#include <string>

class IdCard
{
private:
    int number;
    std::string category;
public:
    IdCard();                       // default
    explicit IdCard(int n);         // number only
    IdCard(int n, std::string cat); // number + category

    void set_number(int newNumber);
    int get_number() const;

    void set_category(std::string cat);
    std::string get_category() const;
};

