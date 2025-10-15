#pragma once

#include <cmath>

class Dot
{
private:
    double x{};
    double y{};

public:
    Dot();                    // default: (0,0)
    Dot(double x, double y);  // value ctor

    // Distance between this and other
    double distanceTo(const Dot& point) const;

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
};

