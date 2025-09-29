#include <iostream>
#include <cstdlib> // std::llabs

int main() {
    long long a, b;
    
    std::cout << "Enter two integers: ";
    if (!(std::cin >> a >> b)) {
        std::cout << "Input error\n";
        return 1;
    }

    a = std::llabs(a);
    b = std::llabs(b);

    long long x = a, y = b;

    if (y == 0) {
        // do-while first step divide by zero
        std::cout << "gcd = " << x << "\n";
    }
    else {
        // do-while next steps
        do {
            long long r = x % y;
            x = y;
            y = r;
        } while (y != 0);
        
        std::cout << "gcd = " << x << "\n";
    }

    if (a != 0 && b != 0) {
        long long lcm = (a / x) * b;
        
        std::cout << "lcm = " << lcm << "\n";
    }

    return 0;
}
