#include <iostream>

int main()
{
    char op{};

    std::cout << "Make your choice, build your dream car (S/V): ";
    std::cin >> op;

    // Normalize to uppercase to accept 's'/'v' too
    op = static_cast<char>(std::toupper(static_cast<unsigned char>(op)));

    switch (op) {
    case 'V':
        std::cout << "Air conditioner, please\n";
        [[fallthrough]]; // intentional fallthrough to 'S'
    case 'S':
        std::cout << "Radio must play\n";
        [[fallthrough]]; // fallthrough to default
    default:
        std::cout << "Round wheels\n";
        std::cout << "Powerful engine\n";
    }

    return 0;
}

