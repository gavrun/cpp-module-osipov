#include <iostream>

// arithmetic mean for array
template <typename T>
double mean(const T* arr, int n) {
    if (n <= 0) {
        std::cerr << "mean(): invalid size\n";
        return 0.0;
    }
    long double sum = 0.0L;
    for (int i = 0; i < n; ++i) {
        sum += static_cast<long double>(arr[i]);
    }
    return static_cast<double>(sum / n);
}

int main()
{
    std::cout << "Arithmetic mean of all array elements.\n";

    int ai[]{ 1, 2, 3, 4, 5 };
    int ni = static_cast<int>(sizeof(ai) / sizeof(ai[0]));
    std::cout << "mean(int[]): " << mean(ai, ni) << "\n";

    long al[]{ 1000000L, 2000000L, 3000000L };
    int nl = static_cast<int>(sizeof(al) / sizeof(al[0]));
    std::cout << "mean(long[]): " << mean(al, nl) << "\n";

    double ad[]{ 1.5, 2.5, 3.5, 4.5 };
    int nd = static_cast<int>(sizeof(ad) / sizeof(ad[0]));
    std::cout << "mean(double[]): " << mean(ad, nd) << "\n";

    const char ac[] = "Hello";
    int nc = static_cast<int>(sizeof(ac) / sizeof(ac[0])) - 1; // without '\0'
    std::cout << "mean(char[]): " << mean(ac, nc) << " (average code)\n";

    return 0;
}

