#include <iostream>
#include <limits>

long long addNumbers(int n);
long long addNumbers(int L, int R);

int main()
{
    std::cout << "Enter positive integer n for sum 1..n: ";
    int n;

    if (!(std::cin >> n)) {
        return 0;
    }

    std::cout << "sum(1.." << n << ") = " << addNumbers(n) << "\n";

    std::cout << "Enter two integers L and R for interval sum [L..R]: ";
    int L, R;

    if (!(std::cin >> L >> R)) {
        return 0;
    }

    std::cout << "sum(" << L << ".." << R << ") = " << addNumbers(L, R) << "\n";
}

// sum 1..n (recursive)
long long addNumbers(int n) {
    if (n <= 0) return 0; // guard for non-positive input
    if (n == 1) return 1; // base case
    
    return n + addNumbers(n - 1); // recursive case
}

// overloaded: sum on interval [L..R] (recursive)
long long addNumbers(int L, int R) {
    if (L > R) return addNumbers(R, L); // normalize order
    if (L == R) return L;               // base case for interval
    
    return R + addNumbers(L, R - 1);  // shrink right bound
}
