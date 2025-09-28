#include <iostream>
using namespace std;

int main()
{
    // --- Sizes of types and usual arithmetic conversions ---
    double f;
    unsigned char l;
    unsigned long r;
    int i;
    float x;

    f = 20;  cout << "sizeof(f) = " << sizeof(f) << endl;
    l = 2;   cout << "sizeof(l) = " << sizeof(l) << endl;
    r = 3;   cout << "sizeof(r) = " << sizeof(r) << endl;
    i = 4;   cout << "sizeof(i) = " << sizeof(i) << endl;

    // Expression uses the usual arithmetic conversions and promotions:
    x = f / (i + l * r);

    cout << "sizeof(l*r) = " << sizeof(l * r) << endl;            // unsigned char promoted to int
    cout << "sizeof(i+l*r) = " << sizeof(i + l * r) << endl;      // result type after promotions
    cout << "sizeof(f/(i+l*r)) = " << sizeof(f / (i + r * l)) << endl; // note: expression equivalent
    cout << "sizeof(x) = " << sizeof(x) << endl;

    system("Pause");

    // --- Integer division vs. floating-point division (casts) ---
    int a = 5;
    float z1, z2;
    z1 = a / 2;                 // integer division first: 5/2 == 2, then converted to float -> 2.0
    z2 = (double)a / 2;         // cast to double: 5.0/2 == 2.5
    auto z21 = double(a) / 2;   // same as above, type is double

    cout << "\t z1 = " << z1 << "\tsize = " << sizeof(z1) << endl;
    cout << "\t z2 = " << z2 << "\tsize = " << sizeof(z2) << endl;
    cout << "\t z21 = " << z21 << "\tsize = " << sizeof(z21) << endl;
    cout << "\t a = " << a << "\tsize = " << sizeof(a) << endl;

    system("Pause");

    // --- Converting negative to unsigned (wraparound per modulo 2^N) ---
    int k1 = -1;
    unsigned int k2 = k1; // implementation-defined representation, but value is converted modulo 2^32 on typical platforms
    cout << "\t k2 = " << k2 << "\tsize = " << sizeof(k2) << endl;

    /*
      C++ defines conversions between signed and unsigned. The resulting unsigned value
      is congruent to the original modulo 2^N (where N is the number of bits of the unsigned type).
    */

    system("Pause");

    // --- Floating-point precision limits (IEEE-754 single vs double) ---
    // Example: subtraction of nearly equal floats shows rounding effects
    float af = 123456789.0f, bf = 123456788.0f, ff;
    ff = af - bf;                       // mathematically 1.0, but float cannot represent all integers exactly at this scale
    cout << "ff = " << ff << endl;      // often prints 1 (or something close), precision is limited

    // Compare the same decimal value stored as double vs float
    double k11 = 123456789.123457;
    float  k22 = 123456789.123457f;     // literal narrowed to float
    cout << "k22 - k11 = " << (k22 - k11) << endl;

    /*
      The same decimal cannot be represented exactly in binary floating-point.
      Double has ~15–17 decimal digits of precision; float has ~6–9.
      When converting/storing, rounding occurs, and subtracting the two shows that discrepancy.
    */

    // --- Catastrophic cancellation / accumulating error example ---
    // Start with 1/3 in float and subtract another 1/3 expressed differently
    float aa = 1.0f, bb = 3.0f;
    float cc = aa / bb;     // approx 0.33333334f
    cc = cc - 1 / 3;        // 1/3 here is integer division -> 0, so cc remains unchanged
    // cc = cc - (float)1 / 3;  // uncomment to compare with true float division
    // cc = cc - 1.f / 3;       // or this: shows cancellation/rounding differences
    cout << "0: " << cc << endl;

    // "Scale" example: repeated subtraction of a tiny float value accumulates rounding error.
    float tabl = 0.00001f;     // small step in seconds (for example)
    float prod = 300.0f;       // starting value (e.g., 300 seconds)
    for (size_t n = 1; n < 10000000; ++n)
    {
        prod = prod - tabl;    // repeated subtraction accumulates rounding error in float
    }
    cout << "Prod = " << prod << endl;  // rarely exactly 200; rounding error accumulates

    /*
      Repeating a small inexact step many times in float accumulates error.
      Neither 300.0f nor 0.00001f is represented exactly in binary float, so the loop drifts.
      Prefer double for better precision, or use integer counters in a precise unit (e.g., microseconds).
    */

    return 0;
}

/*
  More on IEEE-754: floating-point representation and rounding behavior.
  See also standard references for rounding, ULPs, and cancellation.
*/
