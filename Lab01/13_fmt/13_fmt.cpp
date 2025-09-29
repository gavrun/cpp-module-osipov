// 13_fmt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include <fmt/core.h>

#include <string_view>
#include <chrono>
#include <ctime>


int main()
{
    int x = 42;
    std::string name = "Alice";

    // Formatted print
    fmt::print("Hello, {}, the answer is {}!\n", name, x);


    int num = 42;

    // Numbers in other bases
    fmt::print("Hex: {:#x}\n", num);   // 0x2a with prefix

    // Width & alignment
    fmt::print("|{:>10}|\n", 42);  // right
    fmt::print("|{:<10}|\n", 42);  // left
    fmt::print("|{:^10}|\n", 42);  // center

    // Floating point
    double pi = 3.1415926535;
    fmt::print("Fixed: {:.2f}\n", pi);
    fmt::print("Scientific: {:.3e}\n", pi);

    // Format to std::string without printing
    std::string s = fmt::format("Pi = {:.3f}", 3.14159);
    fmt::print("{}\n", s);


    return 0;
}

