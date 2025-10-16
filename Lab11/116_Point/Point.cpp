#include "Point.h"

// Value constructor
Point::Point(double x, double y) : x_(x), y_(y) {}

// Distance to origin (0,0)
double Point::distance() const {
    return std::sqrt(squaredDist_());
}

// Comparison by distance to origin
bool Point::operator<(const Point& other) const {
    double a = squaredDist_();
    double b = other.squaredDist_();
    if (a < b) return true;
    if (a > b) return false;
    // tie-break by (x,y) to keep strict ordering
    if (x_ < other.x_) return true;
    if (x_ > other.x_) return false;
    return y_ < other.y_;
}

// Stream output
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x_ << ", " << p.y_ << ")";
}

// Squared distance without sqrt for comparisons
double Point::squaredDist_() const {
    return x_ * x_ + y_ * y_;
}

