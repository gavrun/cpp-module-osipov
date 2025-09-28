#include <iostream>
#include <iomanip>

int main() {
    // Self-contained: no external headers like "var.h"
    double a = 0.0, b = 0.0, x = 0.0;

    std::cout << "\nInput a and b:\n";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Input error: failed to read numbers.\n";
        return 1;
    }

    if (b == 0.0) {
        std::cerr << "Error: division by zero is not allowed.\n";
        return 1;
    }

    x = a / b;

    // Scientific format with a reasonable precision
    std::cout.setf(std::ios::scientific);
    std::cout << std::setprecision(6);
    std::cout << "\nx = " << x << std::endl;

    // Print addresses (cast to const void* for clear pointer formatting)
    std::cout << "&x = " << static_cast<const void*>(&x) << ' '
        << "&a = " << static_cast<const void*>(&a) << ' '
        << "&b = " << static_cast<const void*>(&b) << '\n';

    return 0;
}
