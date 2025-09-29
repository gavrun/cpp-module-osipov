#include <iostream>
#include <cstdlib>

int main()
{
    long long a, b;

    std::cout << "Enter two integers: ";

    if (!(std::cin >> a >> b)) {
        std::cout << "Input error\n";
        return 1;
    }

    // Work with non-negative values
    a = std::llabs(a);
    b = std::llabs(b);

    // GCD (Greatest Common Divisor), Euclid's algorithm
    long long x = a, y = b;
    while (y != 0) {
        long long r = x % y;
        x = y;
        y = r;
    }

    std::cout << "gcd = " << x << "\n";

    // LCM (Least Common Multiple), if at least one number is non-zero
    if (a != 0 && b != 0) {
        // compute in overflow-aware order: (a / gcd) * b
        long long lcm = (a / x) * b;
        std::cout << "lcm = " << lcm << "\n";
    }

    return 0;
}

