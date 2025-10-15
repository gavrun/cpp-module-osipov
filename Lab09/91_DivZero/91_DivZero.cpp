#include <iostream>
#include <string>

// Custom exception for division by zero
class DivideByZeroError {
public:
    // Store a human-readable message
    DivideByZeroError() : message("Division by zero") {}

    // Print message
    void printMessage() const { std::cout << message << std::endl; }

private:
    std::string message;
};

// Safe division function: throws on zero denominator
float quotient(int num1, int num2) {
    if (num2 == 0) {
        // Throw by value, catch by (const) reference in main
        throw DivideByZeroError();
    }
    // Cast to float to avoid integer division
    return static_cast<float>(num1) / static_cast<float>(num2);
}

int main() {
    std::cout << "Enter two integers (numerator and denominator):\n";

    int number1 = 0;
    int number2 = 0;
    std::cin >> number1;
    std::cin >> number2;

    try {
        float result = quotient(number1, number2);
        std::cout << "Quotient = " << result << std::endl;
    }
    catch (DivideByZeroError& error) {
        std::cout << "ERROR: ";
        error.printMessage();
        return 1; // non-zero code means error
    }

    return 0; // normal exit
}
