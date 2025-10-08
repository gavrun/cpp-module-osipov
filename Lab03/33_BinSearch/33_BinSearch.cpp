#include <iostream>
#include <cmath>
#include <iomanip>

long double firBinSearch(double a, int n);

int main()
{
    double a;
    int n;

    std::cout << "Enter a and n separated by space: ";
    std::cin >> a >> n;

    long double result = firBinSearch(a, n);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

// binary search function for nth root (iterative)
long double firBinSearch(double a, int n)
{
    double L = 0;
    double R = a;

    while (R - L > 1e-10) {     // required precision
        double M = (L + R) / 2; // middle point
        if (std::pow(M, n) < a) // check which side to move
            L = M;
        else
            R = M;
    }

    return R;
}

