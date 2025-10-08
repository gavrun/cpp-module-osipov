#include <iostream>
#include <cmath>

int MyRoot(double a, double b, double c, double& x1, double& x2) {
    const double EPS = 1e-12;

    // near-linear case with precision stabilisation for discriminant, fancy))
    if (std::abs(a) < EPS) {
        if (std::abs(b) < EPS) {
            // either no equation or infinite solutions
            return -1; // no real roots
        }
        x1 = x2 = -c / b;
        return 0; // single root
    }

    double D = b * b - 4.0 * a * c;

    if (D < -EPS) {
        return -1; // no real roots
    }
    else if (std::abs(D) <= EPS) {
        x1 = x2 = -b / (2.0 * a);
        
        return 0; // single root
    }
    else {
        double sqrtD = std::sqrt(D);

        x1 = (-b - sqrtD) / (2.0 * a);
        x2 = (-b + sqrtD) / (2.0 * a);

        return 1; // two real roots
    }
}

int main() {
    std::cout << "Enter coefficients a b c: ";
    double a, b, c;
    
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Input error.\n";
        return 1;
    }

    double x1;
    double x2;

    int flag = MyRoot(a, b, c, x1, x2);

    if (flag == -1) {
        std::cout << "No real roots.\n";
    }
    else if (flag == 0) {
        std::cout << "One real root: x1 = x2 = " << x1 << '\n';
    }
    else { // flag == 1
        std::cout << "Two real roots: x1 = " << x1 << ", x2 = " << x2 << '\n';
    }

    return 0;
}
