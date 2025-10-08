#include <iostream>

bool Input(int& a, int& b) {
    std::cout << "Enter two integers: ";

    // read two numbers
    if (!(std::cin >> a >> b)) {
        // cin errored cleaning
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }

    if (a < 0 || b < 0) {
        std::cerr << "Negative numbers not allowed.\n";
        return false;
    }

    return true;
}


int main()
{
    int a, b;

    if (!Input(a, b)) {
        std::cerr << "Error\n";
        return 1;
    }

    int s = a + b;
    std::cout << "Sum = " << s << std::endl;

    return 0;
}
