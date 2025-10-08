#include <iostream>

void toBinary(int num);

int main() {
    int number;
    std::cout << "Enter positive integer: ";
    std::cin >> number;

    if (number == 0) {
        std::cout << 0;
    }
    else {
        std::cout << "Binary code: ";
        toBinary(number);
    }

    std::cout << std::endl;

    return 0;
}

// recursive up and down to binary 
void toBinary(int num) {
    if (num == 0)
        return; // base case

    toBinary(num / 2);

    std::cout << (num % 2);
}

