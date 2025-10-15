#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <string>

// Domain-specific error
struct TriangleError : public std::runtime_error {
    using std::runtime_error::runtime_error; // what() explanatory string
};

class Triangle {
public:
    // Construct from three sides
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
        validate_(); // throws if invalid
    }

    // Getters
    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }

    // Heron's formula
    double area() const {
        // semiperimeter
        const double p = (a_ + b_ + c_) / 2.0; 
        // guard std::max(0.0, ...)
        const double under = std::max(0.0, p * (p - a_) * (p - b_) * (p - c_));
        return std::sqrt(under);
    }

private:
    double a_{}, b_{}, c_{};

    // Validate sides
    void validate_() {
        if (!(a_ > 0 && b_ > 0 && c_ > 0)) {
            throw TriangleError("Side lengths must be positive.");
        }
        if (a_ > b_ + c_ || b_ > a_ + c_ || c_ > a_ + b_) {
            throw TriangleError("Invalid triangle: one side is greater than the sum of the other two.");
        }
    }
};

int main() {
    std::cout << "Enter three sides (a b c): ";
    double a, b, c;
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Input error: not numbers.\n";
        return 1;
    }

    try {
        Triangle t(a, b, c);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Area = " << t.area() << "\n";
    }
    catch (const TriangleError& ex) {
        std::cerr << "Triangle error: " << ex.what() << "\n";
        return 1;
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << "\n";
        return 2;
    }
    return 0;
}
