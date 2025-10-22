#include <iostream>
#include <concepts>
#include <utility>
#include <type_traits>


// requires presence of operator<
template <typename T>
concept Comparable = requires (const T & a, const T & b) {
    { a < b } -> std::convertible_to<bool>;
};

// template constrained by Comparable
template <Comparable T>
const T& maxOfTwo(const T& a, const T& b) {
    return (a < b) ? b : a;
}

// user-defined type
struct Point {
    int x{ 0 };
    int y{ 0 };

    // compare overload
    bool operator<(const Point& other) const {
        long lhs = 1L * x * x + 1L * y * y;
        long rhs = 1L * other.x * other.x + 1L * other.y * other.y;
        return lhs < rhs;
    }
};

//bool Point::operator<(const Point& other) const {
//    double a = squaredDist_();
//    double b = other.squaredDist_();
//    if (a < b) return true;
//    if (a > b) return false;
//    // tie-break by (x,y) to keep strict ordering
//    if (x_ < other.x_) return true;
//    if (x_ > other.x_) return false;
//    return y_ < other.y_;
//}

// helper printer
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return (os << "Point(" << p.x << ", " << p.y << ")");
}


int main()
{
    std::cout << "Hello Comparable!\n";

    int ai = 10, bi = 42;
    std::cout << "max(int) is " << maxOfTwo(ai, bi) << '\n';

    double ad = 3.14, bd = 2.71;
    std::cout << "max(double) is " << maxOfTwo(ad, bd) << '\n';

    Point p1{ 3, 4 };
    Point p2{ 6, 8 };
    std::cout << "max(Point) is " << maxOfTwo(p1, p2) << '\n';

    return 0;
}

