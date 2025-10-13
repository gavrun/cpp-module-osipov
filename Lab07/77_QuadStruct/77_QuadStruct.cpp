#include <iostream>
#include <cmath>
#include <limits>

// POD with two roots
struct Roots {
    double x1;
    double x2;
};

// Solves [ax^2 + bx + c = 0] for real roots, returns struct
Roots solveQuadratic(double a, double b, double c) {
    Roots r{
        std::numeric_limits<double>::quiet_NaN(),
        std::numeric_limits<double>::quiet_NaN()
    };

    // when a = 0, bx + c = 0  -> x = -c/b (if b != 0)
    if (a == 0.0) { 
        if (b != 0.0) {
            double x = -c / b;
            r.x1 = r.x2 = x; // duplicate
        }
        // else: b == 0 -> either no equation or no real roots, keep NaNs
        return r;
    }

    double D = b * b - 4.0 * a * c;

    if (D > 0.0) {
        // two distinct real roots
        double sqrtD = std::sqrt(D);
        r.x1 = (-b - sqrtD) / (2.0 * a);
        r.x2 = (-b + sqrtD) / (2.0 * a);
    }
    else if (D == 0.0) {
        // one real root (double root)
        double x = (-b) / (2.0 * a);
        r.x1 = r.x2 = x;
    } // else D < 0 -> no real roots, keep NaNs

    return r;
}

int main() {
    std::cout << "Enter a, b, c: ";
    double a, b, c;
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Input error\n";
        return 1;
    }

    Roots res = solveQuadratic(a, b, c);

    // Check for NaN
    bool noReal = std::isnan(res.x1) && std::isnan(res.x2);

    if (noReal) {
        std::cout << "No real roots\n";
    }
    else if (res.x1 == res.x2) {
        std::cout << "One real root: x = " << res.x1 << "\n";
    }
    else {
        std::cout << "Two real roots: x1 = " << res.x1
            << ", x2 = " << res.x2 << "\n";
    }

    return 0;
}
