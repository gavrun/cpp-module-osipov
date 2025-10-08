#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>

int gcd(int m, int n);

int main()
{
    std::cout << "Enter two integers m and n for gcd(m, n): ";
    int m, k;
    
    if (!(std::cin >> m >> k)) {
        return 0;
    }
    
    std::cout << "gcd(" << m << ", " << k << ") = " << gcd(m, k) << "\n";

    return 0;

}

// Euclid's gcd (recursive)
int gcd(int m, int n) {
    m = std::abs(m);
    n = std::abs(n);
    
    if (n == 0) return m; // base case
    
    return gcd(n, m % n);
}
