#include <iostream>
#include <cmath>

double cube_root_pow(double a);
double cube_root_newton(double a);

int main() {
    std::cout << "Enter value of a (cube root): " << std::endl;
    double a;
    std::cin >> a;

    std::cout << "pow:    " << cube_root_pow(a) << '\n';
    std::cout << "newton: " << cube_root_newton(a) << '\n';

    return 0;
}

// using pow(a, 1.0/3.0)
double cube_root_pow(double a) {
    // handle negatives explicitly to avoid NaN with pow
    return (a >= 0.0) ? std::pow(a, 1.0 / 3.0) : -std::pow(-a, 1.0 / 3.0);
}

// using Newton's method
double cube_root_newton(double a) {
    // trivial case
    if (a == 0.0) return 0.0;
    
    // start with correct sign
    double x = a;
    for (int i = 0; i < 30; ++i) { // fixed few iterations
        x = (2.0 * x + a / (x * x)) / 3.0;
    }

    return x;
}

