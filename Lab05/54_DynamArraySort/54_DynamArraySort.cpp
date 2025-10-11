#include <iostream>

// prints array 
void printArray(const int* a, int n) {
    for (int i = 0; i < n; ++i) std::cout << a[i] << '\t'; // tabbed, one line
    std::cout << '\n';
}

// selection sort (ascending)
void selectionSort(int* a, int n) {
    // i points to the "start" of the unsorted tail
    for (int i = 0; i < n; ++i) {
        // assume a[i] is the minimum in [i..n]
        int minIdx = i; 
        
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
    // user input dynamic size
    int n = 0;
    std::cout << "Enter array size (n > 0): ";

    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid size\n";
        return 1;
    }

    // allocate dynamic array
    int* a = new int[n];

    // fill from user input
    std::cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; ++i) {
        std::cout << "a[" << i << "] = ";
        if (!(std::cin >> a[i])) {
            std::cerr << "Input error\n";
            delete[] a; // avoid memory leak on early exit
            return 1;
        }
    }

    std::cout << "Before:\n";
    printArray(a, n);

    // sort
    selectionSort(a, n);

    std::cout << "After:\n";
    printArray(a, n);

    // free memory
    delete[] a;
    a = nullptr;

    return 0;
}

