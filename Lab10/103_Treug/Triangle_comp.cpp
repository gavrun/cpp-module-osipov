#include "Triangle_comp.h"
#include <cmath>

void Triangle_comp::printSides() const {
    double ab, bc, ca; sides_(ab, bc, ca);
    std::cout << std::fixed << std::setprecision(2)
        << "AB = " << ab << ", BC = " << bc << ", CA = " << ca << "\n";
}

double Triangle_comp::perimeter() const {
    double ab, bc, ca; sides_(ab, bc, ca);
    return ab + bc + ca;
}

double Triangle_comp::area() const {
    double ab, bc, ca; sides_(ab, bc, ca);
    const double p = (ab + bc + ca) / 2.0;
    const double under = std::max(0.0, p * (p - ab) * (p - bc) * (p - ca));
    return std::sqrt(under);
}

