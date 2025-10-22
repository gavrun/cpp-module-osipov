#include <iostream>
#include <concepts>

//template <typename T>
//requires std::integral<T>
//T Factorial(T n) { }

// only integral (signed/unsigned) types match
template <std::integral T>
T Factorial(T n) {
    if (n < 0) {
        std::cerr << "Factorial: negative input, returning 0\n";
        return 0;
    }
    if (n <= 1) return 1;

    return n * Factorial(n - 1);
}

int main()
{
    int n = 5;
    double x = 5.0;

    std::cout << "Factorial(" << n << ") = " << Factorial(n) << "\n";

    std::cout << "Factorial(" << x << ") = " << Factorial(x) << "\n";
}

