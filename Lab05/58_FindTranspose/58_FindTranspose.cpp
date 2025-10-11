#include <iostream>
#include <vector>

// Linear search with transposition (in-place) for raw array
int find_with_transposition(int* a, int n, int key) {
    // invalid input or empty array
    if (!a || n <= 0) return -1;

    // go through all
    for (int i = 0; i < n; ++i) {
        if (a[i] == key) {
            if (i > 0) {
                // swap a[i] and a[i-1]
                int tmp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = tmp;
                
                return i - 1; // returns index after transposition
            }
            return 0; // found, no swap
        }
    }
    return -1; // not found
}

// Convenience overload (passing raw pointer and size) for vector
int find_with_transposition(std::vector<int>& v, int key) {
    return v.empty() ? -1 : find_with_transposition(v.data(), static_cast<int>(v.size()), key);
}

int main() {
    // Read array size and elements
    int n;

    std::cout << "n = ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "bad n\n";
        return 1;
    }

    // Create
    std::vector<int> a(n);

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    // Query keys 
    std::cout << "Find key (enter integer to find OR non-integer to stop):\n";
    int key;
    while (std::cin >> key) {
        int pos = find_with_transposition(a, key);

        if (pos == -1) {
            std::cout << "not found\n";
        }
        else {
            std::cout << "found at index (after swap): " << pos << "\n";
        }

        // print current array state
        std::cout << "array: ";
        for (int x : a) std::cout << x << ' ';
        std::cout << "\n";
    }

    return 0;
}
