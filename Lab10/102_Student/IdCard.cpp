#include "IdCard.h"

IdCard::IdCard() : number(0), category("Not defined") {}

IdCard::IdCard(int n) : number(n), category("Not defined") {}

IdCard::IdCard(int n, std::string cat) : number(n), category(std::move(cat)) {}

void IdCard::set_number(int newNumber) { number = newNumber; }
int IdCard::get_number() const { return number; }

void IdCard::set_category(std::string cat) { category = std::move(cat); }
std::string IdCard::get_category() const { return category; }

