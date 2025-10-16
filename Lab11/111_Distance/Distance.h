#pragma once

#include <iosfwd>

class Distance
{
private:
    int   feet;
    float inches;

    // Keep inches in [0..12] range and adjust feet
    void normalize_();

public:
    // Default ctor
    Distance();

    // Value ctor
    Distance(int ft, float in);

    // Input 
    void getdist();

    // Console print 
    void showdist() const;

    // Binary plus +
    Distance operator+(const Distance& rhs) const;

    // Binary minus - 
    friend Distance operator-(const Distance& a, const Distance& b);

    // Binary stream output << 
    friend std::ostream& operator<<(std::ostream& out, const Distance& d);
};

