#include <iostream>
#include <cmath>
#include <limits>
#include <tuple>


// Solves [ax^2 + bx + c = 0] for real roots, returns tuple
std::tuple<double, double, bool> solveQuadratic(double a, double b, double c) {
    //no real roots, keep NaNs
    double x1 = std::numeric_limits<double>::quiet_NaN();
    double x2 = std::numeric_limits<double>::quiet_NaN();
    bool hasRoots = false;

    // when a = 0, bx + c = 0  -> x = -c/b (if b != 0)
    if (a == 0.0) { 
        if (b != 0.0) {
            x1 = x2 = -c / b;
            hasRoots = true;
        }
        return std::make_tuple(x1, x2, hasRoots);
    }

    double D = b * b - 4.0 * a * c;

    if (D > 0.0) {
        // two distinct real roots
        double sqrtD = std::sqrt(D);
        x1 = (-b - sqrtD) / (2 * a);
        x2 = (-b + sqrtD) / (2 * a);
        hasRoots = true;
    }
    else if (D == 0.0) {
        // one real root (double root)
        x1 = x2 = (-b) / (2 * a);
        hasRoots = true;
    } // else D < 0 -> no real roots, keep NaNs

    return std::make_tuple(x1, x2, hasRoots);
}

int main() {
    std::cout << "Enter a, b, c: ";
    double a, b, c;
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Input error\n";
        return 1;
    }

    // ?all func and extract values from tuple
    std::tuple<double, double, bool> result = solveQuadratic(a, b, c);
    double x1 = std::get<0>(result);
    double x2 = std::get<1>(result);
    bool hasRoots = std::get<2>(result);

    // unpack structured binding
    //auto [x1, x2, hasRoots] = solveQuadratic(a, b, c);

    if (!hasRoots) {
        std::cout << "No real roots\n";
    }
    else if (x1 == x2) {
        std::cout << "One real root: x = " << x1 << "\n";
    }
    else {
        std::cout << "Two real roots: x1 = " << x1
            << ", x2 = " << x2 << "\n";
    }

    return 0;
}
