#include "Dot.h"
#include <cmath>

Dot::Dot() : x(0.0), y(0.0) {}

Dot::Dot(double x, double y) : x(x), y(y) {}

// Distance between Dots
double Dot::distanceTo(const Dot& point) const {
    const double dx = point.getX() - x;
    const double dy = point.getY() - y;

    return std::sqrt(dx * dx + dy * dy);
}

