#include <iostream>
#include <cmath> 

double area(double side);
double area(double a, double b, double c);



int main()
{
    std::cout << "Select type of triangle:\n";
    std::cout << "1 - equilateral\n";
    std::cout << "2 - scalene\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        double a;
        std::cout << "Enter length of a side: ";
        std::cin >> a;
        std::cout << "Area of equilateral triangle is: " << area(a) << std::endl;
    }
    else if (choice == 2) {
        double a, b, c;
        std::cout << "Enter lengths of 3 sides: ";
        std::cin >> a >> b >> c;
        std::cout << "Area of scalene triangle is: " << area(a, b, c) << std::endl;
    }
    else {
        std::cout << "Error: invalid selection.\n";
    }

    return 0;
}

// equilateral triangle
double area(double side) {
    return (sqrt(3) / 4) * side * side;
}

// scalene triangle
double area(double a, double b, double c) {
    // verify
    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "Error: triangle with such sides does not exist.\n";
        return 0;
    }
    // area
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

