#pragma once

#include <ostream>
#include <cmath>

class Point
{
public:
    Point() = default;
    Point(double x, double y);
        
    double distance() const;

    bool operator<(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

private:
    double x_{ 0.0 };
    double y_{ 0.0 };

    double squaredDist_() const;
};

