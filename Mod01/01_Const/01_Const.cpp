#include <iostream>
using namespace std;

int main()
{
    // Examples of declaring constants
    const double gravity1{ 9.8 };
    const double gravity11 = 9.8;
    // gravity1 = 9.9; // Error: const variable cannot be modified
    // const double gravity; // Error: must be initialized when declared

    // Using const with user input
    cout << "Enter your age: ";
    int age;
    cin >> age;

    const int usersAge1 = age;   // valid: age is known at runtime
    const int usersAge2{ age };  // same, but with brace initialization

    cout << "Age: " << age << endl;
    cout << "usersAge1: " << usersAge1 << endl;
    cout << "usersAge2: " << usersAge2 << endl;

    // Examples of constexpr (must be known at compile time)
    constexpr double gravity2{ 9.8 };   // ok
    constexpr double gravity3 = 9.8;    // ok
    constexpr int sum1{ 4 + 5 };        // ok, computed at compile time
    constexpr int sum2 = 4 + 5;         // ok

    // constexpr int myAge{ age };      // Error: age is not known at compile time
    // constexpr int myAge = age;       // Error: cannot use runtime value

    return 0;
}
