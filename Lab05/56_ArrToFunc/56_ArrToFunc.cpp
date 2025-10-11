#include <iostream>
#include <limits>
#include <algorithm>
#include <utility>

// sum of all elements
long sumAll(int n, const int* a) {
    long s = 0;
    for (int i = 0; i < n; ++i) s += a[i];
    return s;
}

// sum of negative elements
long sumNeg(int n, const int* a) {
    long s = 0;
    for (int i = 0; i < n; ++i) if (a[i] < 0) s += a[i];
    return s;
}

// sum of positive elements
long sumPos(int n, const int* a) {
    long s = 0;
    for (int i = 0; i < n; ++i) if (a[i] > 0) s += a[i];
    return s;
}

// sums at even/odd indices
long sumEvenIdx(int n, const int* a) {
    long s = 0;
    for (int i = 0; i < n; i += 2) s += a[i];
    return s;
}
long sumOddIdx(int n, const int* a) {
    long s = 0;
    for (int i = 1; i < n; i += 2) s += a[i];
    return s;
}

// index of min/max element
int minIndex(int n, const int* a) {
    if (n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i) if (a[i] < a[idx]) idx = i;
    return idx;
}
int maxIndex(int n, const int* a) {
    if (n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i) if (a[i] > a[idx]) idx = i;
    return idx;
}

// product of elements strictly between min and max (by index)
// returns pair: (hasBetween, product)
std::pair<bool, long> productBetweenMinMax(int n, const int* a) {
    if (n <= 2) return { false, 1 };
    int iMin = minIndex(n, a);
    int iMax = maxIndex(n, a);
    if (iMin == -1 || iMax == -1) return { false, 1 };

    int left = std::min(iMin, iMax);
    int right = std::max(iMin, iMax);
    if (right - left <= 1) return { false, 1 }; // adjacent, nothing between

    long prod = 1;
    for (int i = left + 1; i < right; ++i) prod *= a[i];
    return { true, prod };
}

// average as double
double avg(int n, const int* a) {
    if (n == 0) return 0.0;
    return static_cast<double>(sumAll(n, a)) / n;
}

// selection sort (ascending, in-place)
void selectionSort(int n, int* a) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIdx]) minIdx = j;
        if (minIdx != i) std::swap(a[i], a[minIdx]);
    }
}

// print helper
void printArray(const int* a, int n) {
    for (int i = 0; i < n; ++i) std::cout << a[i] << '\t';
    std::cout << '\n';
}

int main() {
    const int n = 10;
    int mas[n];

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "mas[" << i << "] = ";
        std::cin >> mas[i];
    }

    // calculations via functions
    long sAll = sumAll(n, mas);
    long sNeg = sumNeg(n, mas);
    long sPos = sumPos(n, mas);
    long sEven = sumEvenIdx(n, mas);
    long sOdd = sumOddIdx(n, mas);
    int iMin = minIndex(n, mas), iMax = maxIndex(n, mas);
    double aMean = avg(n, mas);
    auto betweenInfo = productBetweenMinMax(n, mas);
    bool hasBetween = betweenInfo.first;
    long prodBetween = betweenInfo.second;

    // outputs
    std::cout << "\nSum of all elements: " << sAll << '\n';
    std::cout << "Average value: " << aMean << '\n';
    std::cout << "Sum of negative elements: " << sNeg << '\n';
    std::cout << "Sum of positive elements: " << sPos << '\n';
    std::cout << "Sum (even indices): " << sEven << '\n';
    std::cout << "Sum (odd  indices): " << sOdd << '\n';
    std::cout << "Min value = " << mas[iMin] << " at index " << iMin << '\n';
    std::cout << "Max value = " << mas[iMax] << " at index " << iMax << '\n';

    if (hasBetween)
        std::cout << "Product of elements between min and max: " << prodBetween << '\n';
    else
        std::cout << "No elements between min and max (they are adjacent).\n";

    // selection
    selectionSort(n, mas);
    std::cout << "Sorted: ";
    printArray(mas, n);

    return 0;
}

