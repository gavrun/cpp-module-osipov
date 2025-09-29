#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x1, x2;
    
    std::cout << "x1 = ";
    std::cin >> x1;
    std::cout << "x2 = ";
    std::cin >> x2;

    std::cout << "\tx\t\tsin(x)\n";

    const double step = 0.01;
    double x = x1;

    // Task 1 pre-condition
    while (x <= x2 + 1e-12) { // tiny epsilon to soften FP rounding
        double y = std::sin(x);
        std::cout << '\t' << x << "\t\t" << y << '\n';
        x += step;
    }

    return 0;
}
