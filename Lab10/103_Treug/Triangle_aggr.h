#pragma once

#include "Dot.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

class Triangle_aggr
{
public:
    // Store pointers to points (aggregation)
    Triangle_aggr(const Dot* a, const Dot* b, const Dot* c)
        : A(a), B(b), C(c) {
        if (!A || !B || !C) throw std::invalid_argument("Null Dot pointer");
    }

    // Triangle side lengths
    void printSides() const;

    // Perimeter and area (Heron's formula)
    double perimeter() const;
    double area() const;

    // resetting which external points we "aggregate"
    void reset(const Dot* a, const Dot* b, const Dot* c) {
        if (!a || !b || !c) throw std::invalid_argument("Null Dot pointer");
        A = a; B = b; C = c;
    }

private:
    const Dot* A{};
    const Dot* B{};
    const Dot* C{};

    void sides_(double& ab, double& bc, double& ca) const {
        ab = A->distanceTo(*B);
        bc = B->distanceTo(*C);
        ca = C->distanceTo(*A);
    }
};

