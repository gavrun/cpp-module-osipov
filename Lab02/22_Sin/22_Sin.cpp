#include <iostream>

#include <cmath>
#include <iomanip>


int main()
{
    double x, x1, x2, y;

    std::cout << "x1 = ";
    std::cin >> x1;
    std::cout << "x2 = ";
    std::cin >> x2;

    std::cout << "\tx\t\tsin(x)\n";

    x = x1;
    do {
        y = std::sin(x); // radians
        
        std::cout << '\t' << x << "\t\t" << y << '\n';
        x = x + 0.01;
    } while (x <= x2);

    return 0;
}
