#include <iostream>
#include "Distance.h"

int main() {
    Distance dist1, dist2, dist3, dist4;

    dist1.getdist();
    dist2.getdist();

    dist3 = dist1 + dist2;
    dist4 = dist1 + dist2 + dist3;

    // std::cout << "\ndist1 = "; dist1.showdist();
    // std::cout << "dist2 = ";  dist2.showdist();
    // std::cout << "dist3 = ";  dist3.showdist();
    // std::cout << "dist4 = ";  dist4.showdist();

    std::cout << "\ndist1 = " << dist1
        << "dist2 = " << dist2
        << "dist3 = " << dist3
        << "dist4 = " << dist4;

    // Distance dsub = dist4 - dist3;
    // std::cout << "dist4 - dist3 = " << dsub;

    return 0;
}
