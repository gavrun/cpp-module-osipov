#include <iostream>
#include <iomanip>   // for std::fixed and std::setprecision
#include <string>

using namespace std;

int main()
{
    // Option 1 (manipulators): set fixed format and precision for floating output
    cout << fixed << setprecision(3);

    // Option 2 (equivalent, using member functions):
    // cout.precision(3);
    // cout.setf(ios::fixed);

    double p = 1234.65792889;
    cout << "Example value p = " << p << endl; // prints with 3 digits after the decimal point

    double a, b;

    cout << "\nEnter a and b:\n";
    cin >> a;
    cin >> b;

    // Basic safety: avoid division by zero
    if (b == 0.0)
    {
        cout << "\nError: division by zero is undefined.\n";
    }
    else
    {
        double x = a / b; // compute result
        cout << "\nx = " << x << endl; // printed with the same formatting (fixed, precision=3)
    }

    // Windows-only: keep the console window open when running from Visual Studio
    system("pause");
    return 0;
}
