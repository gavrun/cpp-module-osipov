#include <iostream>
#include "Time.h"

int main()
{
    try {
        std::cout << std::fixed;

        // Construct & normalize
        Time t1(1, 70, 90);   // 02:11:30
        Time t2(0, 45, 50);   // 00:45:50
        Time t3(0, 0, 9);   // 00:00:09

        std::cout << "t1 = " << t1 << "\n";
        std::cout << "t2 = " << t2 << "\n";

        // Addition
        Time t_sum = t1 + t2;
        std::cout << "t1 + t2 = " << t_sum << "\n";

        // Subtraction ok
        Time t_diff = t1 - t2;
        std::cout << "t1 - t2 = " << t_diff << "\n";

        // Subtraction should throw
        try {
            Time t_bad = t2 - t1;
            std::cout << "t2 - t1 = " << t_bad << "\n";
        }
        catch (const Time::TimeError& e) {
            std::cerr << "Time error: " << e.what() << "\n";
        }

        // Addition real type
        Time plus5 = t2 + 5.0;
        Time plusN = 12.7 + t2;
        std::cout << "t2 + 5s  = " << plus5 << "\n";
        std::cout << "12.7s + t2 = " << plusN << "\n";

        // Comparison
        std::cout << std::boolalpha;
        std::cout << "t1 == t2? " << (t1 == t2) << "\n";
        std::cout << "t1 >  t2? " << (t1 > t2) << "\n";
        std::cout << "t1 >= t1? " << (t1 >= t1) << "\n";

        // Negative seconds
        try {
            Time t_neg = t3 + (-10.0); //below zero
            std::cout << t_neg << "\n";
        }
        catch (const Time::TimeError& e) {
            std::cerr << "Time error: " << e.what() << "\n";
        }

        // Invalid ctor
        try {
            Time t_bad(-1, 0, 0);
            std::cout << t_bad << "\n";
        }
        catch (const Time::TimeError& e) {
            std::cerr << "Time error: " << e.what() << "\n";
        }
    }
    catch (const Time::TimeError& e) {
        std::cerr << "Time error: " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << "\n";
        return 2;
    }
    return 0;
}
