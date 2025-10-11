#include <iostream>
#include <limits>


int main() {
    const int n = 10;
    int mas[n];

    std::cout << "Enter " << n << " integers mas[i] one by one or all " << n << " separated by spaces: "; // one prompt

    // input from keyboard
    for (int i = 0; i < n; ++i) {
        std::cout << "mas[" << i << "] = ";
        std::cin >> mas[i];
    }

    // sums
    long sumAll = 0;       // long >> long long 
    long sumNeg = 0;
    long sumPos = 0;
    long sumEvenIdx = 0;   // indices 0,2,4,...
    long sumOddIdx = 0;    // indices 1,3,5,...

    // calculate all sums
    for (int i = 0; i < n; ++i) {
        sumAll += mas[i];

        if (mas[i] < 0) sumNeg += mas[i];
        if (mas[i] > 0) sumPos += mas[i];

        if (i % 2 == 0) sumEvenIdx += mas[i];
        else            sumOddIdx += mas[i];
    }

    // average
    double avg = static_cast<double>(sumAll) / n; // real division not to lose fractional part

    // min/max values and indices
    int minVal = mas[0], maxVal = mas[0];
    int minIdx = 0, maxIdx = 0;
    
    for (int i = 1; i < n; ++i) {
        if (mas[i] < minVal) { minVal = mas[i]; minIdx = i; }
        if (mas[i] > maxVal) { maxVal = mas[i]; maxIdx = i; }
    }

    // product of elements which are between min and max
    int left = std::min(minIdx, maxIdx);
    int right = std::max(minIdx, maxIdx);
    long prodBetween = 1;              // empty product convention
    bool hasBetween = (right - left > 1);
    
    if (hasBetween) {
        for (int i = left + 1; i < right; ++i) {
            prodBetween *= mas[i];
        }
    }

    // outputs
    std::cout << "\nSum of all elements: " << sumAll << std::endl;
    std::cout << "Average value: " << avg << std::endl;

    std::cout << "Sum of negative elements: " << sumNeg << std::endl;
    std::cout << "Sum of positive elements: " << sumPos << std::endl;
    std::cout << "Sum (even indices): " << sumEvenIdx << std::endl;
    std::cout << "Sum (odd  indices): " << sumOddIdx << std::endl;

    std::cout << "Min value = " << minVal << " at index " << minIdx << std::endl;
    std::cout << "Max value = " << maxVal << " at index " << maxIdx << std::endl;

    if (hasBetween) {
        std::cout << "Product of elements between min and max: " << prodBetween << std::endl;
    }
    else {
        std::cout << "No elements between min and max (they are adjacent).\n";
    }

    return 0;
}
