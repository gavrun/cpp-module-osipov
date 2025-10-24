#include <iostream>

class Point
{
private:
    int _x, _y;

public:
    Point() : _x(0), _y(0) {}

    Point(int init_X, int init_Y) : _x(init_X), _y(init_Y) {}

    Point operator+(const Point &other) const
    {
        return Point(this->_x + other._x, this->_y + other._y);
    }

    Point &operator+=(const Point &other)
    {
        this->_x += other._x;
        this->_y += other._y;
        return *this;
    }

    Point operator+(int value) const
    {
        return Point(this->_x + value, this->_y + value);
    }
    
    // void print() const {
    //     std::cout << "Point(" << _x << ", " << _y << ")" << std::endl;
    // }
};

int main()
{
    Point pt1(1, 1), pt2(2, 2), pt3;

    pt3 = pt1 + pt2;
    pt2 += pt1;
    pt3 = pt1 + 5;

    // std::cout << "pt2 is now: ";
    // pt2.print();
    // std::cout << "pt3 is now: ";
    // pt3.print();

    return 0;
}