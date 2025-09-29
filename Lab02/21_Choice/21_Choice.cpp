#include <iostream>

int main()
{
    char op{};

    std::cout << "Make your choice, build your dream car (S/V): ";
    std::cin >> op;

    switch (op)
    {
    case 'S':
        std::cout << "Radio must play\n";
        std::cout << "Round wheels\n";
        std::cout << "Powerful engine\n";
        break;

    case 'V':
        std::cout << "Air conditioner, please\n";
        std::cout << "Radio must play\n";
        std::cout << "Round wheels\n";
        std::cout << "Powerful engine\n";
        break;

    default:
        std::cout << "Round wheels\n";
        std::cout << "Powerful engine\n";
    }

    return 0;
}

