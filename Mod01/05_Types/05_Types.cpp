#include <iostream>
#include <iomanip>

int main() {
    // Part 1: sizes and mixed arithmetic
    double f = 20.0;
    unsigned char l = 2;
    unsigned long r = 3;
    int i = 4;
    float x = 0.0f;

    std::cout << "sizeof(f) = " << sizeof(f) << '\n';
    std::cout << "sizeof(l) = " << sizeof(l) << '\n';
    std::cout << "sizeof(r) = " << sizeof(r) << '\n';
    std::cout << "sizeof(i) = " << sizeof(i) << '\n';

    // Make the integer part explicit to show conversions
    unsigned long denom = static_cast<unsigned long>(i)
        + static_cast<unsigned long>(l) * r;

    std::cout << "sizeof(l * r) = " << sizeof(l * r) << '\n';
    std::cout << "sizeof(i + l * r) = " << sizeof(i + l * r) << '\n';
    std::cout << "sizeof(f / (i + l * r)) = " << sizeof(f / (i + l * r)) << '\n';

    if (denom != 0UL) {
        double t = f / static_cast<double>(denom);
        x = static_cast<float>(t); // intentional narrowing
    }
    else {
        std::cout << "Warning: division by zero avoided.\n";
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "denominator (i + l * r) = " << denom << '\n';
    std::cout << "x = f / (i + l * r) = " << x << '\n';
    std::cout << "sizeof(x) = " << sizeof(x) << '\n';

    // Part 2: integer vs floating division
    int a = 5;
    float z1 = a / 2;                 // integer division, then converted to float (2 -> 2.0f)
    double z2 = static_cast<double>(a) / 2; // floating division (2.5)
    auto z21 = double(a) / 2;         // also 2.5

    std::cout << "\tz1 = " << z1 << "\tsize = " << sizeof(z1) << '\n';
    std::cout << "\tz2 = " << z2 << "\tsize = " << sizeof(z2) << '\n';
    std::cout << "\tz21 = " << z21 << "\tsize = " << sizeof(z21) << '\n';
    std::cout << "\ta = " << a << "\tsize = " << sizeof(a) << '\n';

    // Part 3: signed to unsigned conversion (wrap-around modulo 2^N)
    int k1 = -1;
    unsigned int k2 = static_cast<unsigned int>(k1);
    std::cout << "\tk2 = " << k2 << "\tsize = " << sizeof(k2) << '\n';
    // Note: converting negative to unsigned is well-defined modulo 2^N.

    // Part 4: floating-point pitfalls (IEEE-754)
    float af = 123456789.0f, bf = 123456788.0f;
    float ff = af - bf; // may be 0, 8, 16, etc. depending on rounding/spacing
    std::cout << "ff = " << ff << '\n';

    double k11 = 123456789.123457;
    float  k22 = 123456789.123457f; // fewer significant digits than double
    std::cout << "k22 - k11 = " << static_cast<double>(k22) - k11 << '\n';

    // Intermediate rounding matters: keep all operands in the same precision
    float aa = 1.0f, bb = 3.0f;
    float cc = aa / bb;
    cc = cc - 1.0f / 3.0f; // non-zero due to rounding
    std::cout << "cc (aa/bb - 1/3) = " << cc << '\n';

    // Part 5: accumulation example ("packaging")
    float tabl = 0.00001f; // one tablet in kg
    float prod = 300.0f;   // bunker load in kg
    for (std::size_t n = 1; n < 10'000'000; ++n) {
        prod = prod - tabl; // tiny decrement may round away at this magnitude in float
    }
    std::cout << "Prod = " << prod << '\n';
    // Explanation: ulp near 300.0f is ~3e-5; step 1e-5 may not change the value each iteration.

    return 0;
}
