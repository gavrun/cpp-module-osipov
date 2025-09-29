#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // operands and user answer
    int a = 0, b = 0, c = 0;  
    // number of wrong answers
    int wrong = 0; 
    // total number of questions
    const int total = 10;        

    for (int i = 1; i <= total; ++i) {
        // random operands in range [1..10]
        a = std::rand() % 10 + 1;
        b = std::rand() % 10 + 1;

        std::cout << "[" << i << "/" << total << "] " << a << " * " << b << " = ";

        if (!(std::cin >> c)) {
            std::cout << "Invalid input. Exiting.\n";
            return 1;
        }

        if (a * b != c) {
            ++wrong; // increment wrong answers counter
            std::cout << "Error! " << a << " * " << b << " = " << (a * b) << "\n";
        }
    }

    std::cout << "Count error: " << wrong << "\n";

    return 0;
}
