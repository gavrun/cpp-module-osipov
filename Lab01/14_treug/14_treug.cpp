#include <iostream>

#include <iomanip>
#include <cmath>



int main()
{
    std::cout << "Enter the perimeter of an equilateral triangle:\n";
    
    double Perimeter;
    
    if (!(std::cin >> Perimeter)) {
        std::cerr << "Input error: not a number.\n";
        return 1;
    }
    if (Perimeter <= 0.0) {
        std::cerr << "Input error: perimeter must be positive.\n";
        return 1;
    }

    const double aSide = Perimeter / 3.0;
    const double semiPerimeter = Perimeter / 2.0;

    // Heron's formula 
    const double sArea = std::sqrt(semiPerimeter * (semiPerimeter - aSide) * (semiPerimeter - aSide) * (semiPerimeter - aSide));

    std::cout << std::fixed << std::setprecision(2);

    // Table
    std::cout << "\n"
        << std::left << std::setw(12) << "Side"
        << std::left << std::setw(12) << "Area" << '\n';
    std::cout << std::left << std::setw(12) << aSide
        << std::left << std::setw(12) << sArea << '\n';

    return 0;
}

