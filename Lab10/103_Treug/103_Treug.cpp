#include <iostream>
#include <iomanip>
#include "Dot.h"
#include "Triangle_comp.h"
#include "Triangle_aggr.h"

int main() {
    // all based on the 94_Treug.cpp

    std::cout << std::fixed << std::setprecision(2);

    // Define points of 3-4-5 triangle
    Dot a(0, 0), b(3, 0), c(0, 4); 

    // Composition: triangle owns copies of points
    Triangle_comp tComp(a, b, c);
    std::cout << "Example of Composition\n";
    tComp.printSides();
    std::cout << "Perimeter = " << tComp.perimeter() << "\n";
    std::cout << "Area      = " << tComp.area() << "\n\n";

    // Aggregation: triangle refers to external objects
    Triangle_aggr tAgg(&a, &b, &c);
    std::cout << "Example of Aggregation\n";
    tAgg.printSides();
    std::cout << "Perimeter = " << tAgg.perimeter() << "\n";
    std::cout << "Area      = " << tAgg.area() << "\n";

    return 0;
}

