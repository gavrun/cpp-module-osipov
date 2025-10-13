#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>

// prints tuple (a, b, c)
void printTupleOfThree(std::tuple<std::string, int, double> t) {
    // access elements by compile-time indices
    std::cout << "("
        << std::get<0>(t) << ", "
        << std::get<1>(t) << ", "
        << std::get<2>(t) << ")"
        << std::endl;
}

int main() {
    std::vector<std::string> v1{ "one", "two", "three", "four", "five", "six" };

    std::vector<int> v2{ 1, 2, 3, 4, 5, 6 };

    std::vector<double> v3{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    auto t0 = std::make_tuple(v1[0], v2[0], v3[0]);

    printTupleOfThree(t0);

    return 0;
}
