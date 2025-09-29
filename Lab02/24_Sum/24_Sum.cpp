#include <iostream>
#include <limits>
#include <utility>

int main() {
    int k, m;
    long long s = 0; // wide type for safety, though 1..100 fits in int

    std::cout << "Enter k and m (integers): ";
    if (!(std::cin >> k >> m)) {
        std::cerr << "Input error.\n";
        return 1;
    }

    // Normalize order: ensure k <= m
    if (k > m) std::swap(k, m);

    // Optional clamping to [1, 100]
    if (k < 1) k = 1;
    if (m > 100) m = 100;

    // Sum 1..100 skipping (k, m) open interval
    for (int i = 1; i <= 100; ++i) {
        if (i > k && i < m) {
            continue; // skip numbers between k and m
        }
        s += i;
    }

    std::cout << "Sum = " << s << '\n';

    return 0;
}
