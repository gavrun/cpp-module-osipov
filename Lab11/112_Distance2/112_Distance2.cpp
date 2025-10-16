#include <iostream>
#include <iomanip>
#include "Distance.h"

int main() {
    // Construct from meters 
    Distance dist1 = 2.35F; // (implicit) meters -> feet+inches

    Distance dist2(5, 8.0f); // 5 ft 8 in

    // Declare float
    float mtrs = 0.0f;

    // Explicit cast to float (meters)
    mtrs = static_cast<float>(dist1);

    // Implicit conversion to float (meters)
    float mtrs2 = dist2; // operator float()

    std::cout << "dist1 (from 2.35 m) = " << dist1;
    std::cout << "dist2 (5 ft 8 in)   = " << dist2;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "meters(dist1) explicit = " << mtrs << " m\n";
    std::cout << "meters(dist2) implicit = " << mtrs2 << " m\n";

    // Test if arithmetics still work
    Distance dist3 = dist1 + dist2;
    std::cout << "dist3 = dist1 + dist2  = " << dist3;

    return 0;
}

