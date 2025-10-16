#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"

int main()
{
    std::vector<Point> v_points;

    v_points.push_back(Point(1, 2));
    v_points.push_back(Point(10, 12));
    v_points.push_back(Point(21, 7));
    v_points.push_back(Point(4, 8));

    std::cout << "Before:\n";

    // Print (operator<<)
    for (const auto& p : v_points) {
        std::cout 
            << "Point " << p 
            << "  distance to origin = " 
            << p.distance() << '\n';
    }

    // Sort by distance to origin (operator<)
    std::sort(v_points.begin(), v_points.end());

    std::cout << "After:\n";
    
    for (auto& point : v_points) {
        std::cout << "Point " << point
            << "  distance = "
            << point.distance() << '\n';
    }

    return 0;
}

