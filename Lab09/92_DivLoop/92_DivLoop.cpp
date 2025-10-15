#include <iostream>
#include <string>


// Custom exception for division by zero
class DivideByZeroError {
public:
    DivideByZeroError() : message("Division by zero") {}
    void printMessage() const { std::cout << message << std::endl; }
private:
    std::string message;
};

// Safe division function
float quotient(int num1, int num2) {
    if (num2 == 0) {
        throw DivideByZeroError();
    }
    return static_cast<float>(num1) / static_cast<float>(num2);
}

int main() {
    std::cout << "Enter numerator: ";
    int number1;
    std::cin >> number1;

    // Loop through denominators from -10 to 9
    for (int i = -10; i < 10; ++i) {
        try {
            float result = quotient(number1, i);
            std::cout << number1 << " / " << i << " = " << result << std::endl;
        }
        catch (DivideByZeroError& error) {
            std::cout << number1 << " / " << i << " -> ERROR: ";
            error.printMessage();
        }
    }

    std::cout << "Done.\n";

    return 0;
}
