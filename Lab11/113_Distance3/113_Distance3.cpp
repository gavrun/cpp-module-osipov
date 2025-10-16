#include <iostream>
#include <iomanip>
#include "Distance.h"

int main() {
    Distance dist1 = 2.0F;     // 2 m
    Distance dist2(5, 6.0f);   // 5 ft 6 in

    std::cout << "dist1 = " << dist1;
    std::cout << "dist2 = " << dist2;

    // Mixed additions
    Distance d3 = dist1 + 1.2F;  // Distance + float
    Distance d4 = 1.2F + dist1;  // float + Distance
    Distance d5 = dist2 - 0.5F;  // Distance - float
    Distance d6 = 0.5F - dist1;  // float - Distance

    std::cout << "dist1 + 1.2m = " << d3;
    std::cout << "1.2m + dist1 = " << d4;
    std::cout << "dist2 - 0.5m = " << d5;
    std::cout << "0.5m - dist1 = " << d6;

    return 0;
}

