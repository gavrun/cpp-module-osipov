#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


int FindMaxEven(const std::vector<int>& v) {
    // max even number over iterator and lambda
    auto iter = std::max_element(v.begin(), v.end(), [](int a, int b) {
        // lambda returns true if a<b filtered by parity/evennes
        if (a % 2 != 0 && b % 2 == 0) return true;
        if (a % 2 == 0 && b % 2 != 0) return false;
        return a < b; // compare by value
        });

    // no even numbers
    if (iter == v.end() || *iter % 2 != 0)
        throw std::runtime_error("Even numbers expected");

    return *iter;
}


int main()
{
    // runtime_error safe
    try {
        //std::vector<int> numbers = { 3, 7, 4, 9, 12, 5, 8 };
        std::vector<int> numbers = { 3, 7, 5, 9, 13, 5, 7 };

        std::cout << "Max even: " << FindMaxEven(numbers) << '\n';
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
