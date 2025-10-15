#pragma once

#include "Dot.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

class Triangle_comp
{
public:
    // Store points by value (composition)
    Triangle_comp(const Dot& a, const Dot& b, const Dot& c)
        : A(a), B(b), C(c) {
    }

    // Triangle side lengths
    void printSides() const;

    // Perimeter and area (Heron's formula)
    double perimeter() const;
    double area() const;

private:
    Dot A, B, C;

    void sides_(double& ab, double& bc, double& ca) const {
        ab = A.distanceTo(B);
        bc = B.distanceTo(C);
        ca = C.distanceTo(A);
    }
};

