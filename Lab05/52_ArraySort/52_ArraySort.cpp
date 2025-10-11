#include <iostream>

// Prints array elements in one line
void printArray(const int* a, int n) {
    for (int i = 0; i < n; ++i) std::cout << a[i] << '\t'; // tabbed
    std::cout << '\n';
}

// Selection sort (ascending)
void selectionSort(int* a, int n) {
    // i points to the "start" of the unsorted tail
    for (int i = 0; i < n; ++i) {
        int minIdx = i; // assume a[i] is the minimum in [i..n)
        // find real minimum index on the tail
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) minIdx = j; 
            // minIdx = (a[j] < a[minIdx]) ? j : minIdx;
        }
        // swap if needed
        if (minIdx != i) {
            int buf = a[i];
            a[i] = a[minIdx];
            a[minIdx] = buf;
        }
    }
}

int main() {
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    std::cout << "Before:\n";
    printArray(a, N);

    selectionSort(a, N);

    std::cout << "After:\n";
    printArray(a, N);

    // foreach-style (range-based) printing 
    //std::cout << "After (range-for):\n";
    //for (int x : a) std::cout << x << '\t';
    //std::cout << '\n';

    return 0;
}

