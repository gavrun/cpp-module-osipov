#include <iostream>
#include <vector>
#include <string>

// prints any container separator
template <typename Container>
void Print(const Container& cont, const std::string& separator) {
    bool first = true;
    for (const auto& elem : cont) {
        if (!first)
            std::cout << separator;
        std::cout << elem;
        first = false;
    }
    std::cout << '\n';
}

int main()
{
    std::cout << "Printer!\n";

    std::vector<int> data = { 1, 2, 3, 4 };
    std::vector<std::string> words = { "apple", "banana", "cherry" };

    Print(data, ", ");
    Print(words, " | ");

    return 0;
}

