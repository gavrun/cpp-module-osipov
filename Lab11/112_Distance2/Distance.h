#pragma once

#include <iosfwd>

class Distance {
private:
    int   feet;
    float inches;

    // Meters-to-feet factor (constant per object)
    const float MTF;

    // Normalize inches to [0, 12] and adjust feet
    void normalize_();

public:
    Distance();

    Distance(int ft, float in);

    // Constructure from meters to feet+inches
    // intentionally NOT explicit to allow Distance d = 2.35F;
    Distance(float meters);

    void getdist();

    void showdist() const;

    Distance operator+(const Distance& rhs) const;

    friend Distance operator-(const Distance& a, const Distance& b);

    friend std::ostream& operator<<(std::ostream& out, const Distance& d);

    // Cast to meters (float)
    operator float() const;
};

