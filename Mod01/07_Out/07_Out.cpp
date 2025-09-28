#include <iostream>
#include <iomanip>
#include <string>

int main() {
    // Setup formatting
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);

    double p = 1234.65792889;
    std::cout << "Parameter p = " << p << '\n';

    double a = 0.0, b = 0.0, x = 0.0;
    std::cout << "\nEnter a and b:\n";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Input error.\n";
        return 1;
    }

    if (b == 0.0) {
        std::cerr << "Error: division by zero.\n";
        return 1;
    }

    x = a / b;
    std::cout << "\nx = " << x << '\n';

    return 0;
}
