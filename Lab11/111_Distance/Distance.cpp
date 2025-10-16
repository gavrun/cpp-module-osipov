#include "Distance.h"

#include <iostream>
#include <limits> 

Distance::Distance() : feet(0), inches(0.0f) {}

Distance::Distance(int ft, float in) : feet(ft), inches(in) {
    normalize_();
}

void Distance::normalize_() {
    if (inches >= 12.0f) {
        int add = static_cast<int>(inches / 12.0f);
        feet += add;
        inches -= 12.0f * add;
    }
    while (inches < 0.0f && feet > 0) {
        inches += 12.0f;
        --feet;
    }
    if (feet < 0) { feet = 0; inches = 0.0f; }
}

void Distance::getdist() {
    std::cout << "\nEnter feet: ";
    std::cin >> feet;
    std::cout << "Enter inches: ";
    std::cin >> inches;

    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        feet = 0; inches = 0.0f;
    }
    normalize_();
}

void Distance::showdist() const {
    std::cout << feet << "'-" << inches << "\"\n";
}

// Operator verloads 

Distance Distance::operator+(const Distance& rhs) const {
    int   f = feet + rhs.feet;
    float i = inches + rhs.inches;
    return Distance(f, i); // ctor normalizes
}

Distance operator-(const Distance& a, const Distance& b) {
    float ain = a.feet * 12.0f + a.inches;
    float bin = b.feet * 12.0f + b.inches;
    float din = ain - bin;
    if (din <= 0.0f) return Distance(0, 0.0f);

    int   f = static_cast<int>(din / 12.0f);
    float i = din - f * 12.0f;
    return Distance(f, i);
}

std::ostream& operator<<(std::ostream& out, const Distance& d) {
    out << d.feet << "'-" << d.inches << "\"\n";
    return out;
}

