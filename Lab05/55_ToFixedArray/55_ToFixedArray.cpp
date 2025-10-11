#include <iostream>
#include <ctime>

int main() {
    std::srand(std::time(nullptr)); // seed RNG

    int a, b, c;
    int k = 0;        // number of errors

    const int n = 10; // fixed number of questions
    int mas[n];       // all user answers (size = n)

    // index from 0 to n-1
    for (int i = 0; i < n; ++i) {
        a = std::rand() % 10 + 1; // 1..10
        b = std::rand() % 10 + 1; // 1..10

        // question
        std::cout << a << " * " << b << " = ";
        // answer
        std::cin >> c;

        mas[i] = c; // store answer into array

        // answered wrong?
        if (a * b != c) {
            ++k;
            std::cout << "Error! " << a << " * " << b << " = " << (a * b) << "\n";
        }
    }

    // print all answers
    std::cout << "\nAll: ";
    for (int i = 0; i < n; ++i) std::cout << mas[i] << ' ';
    std::cout << "\nCount error: " << k << "\n";
    return 0;
}


//23_Iter.cpp

//int main() {
//
//    std::srand(static_cast<unsigned>(std::time(nullptr)));
//
//    // operands and user answer
//    int a = 0, b = 0, c = 0;
//    // number of wrong answers
//    int wrong = 0;
//    // total number of questions
//    const int total = 10;
//
//    for (int i = 1; i <= total; ++i) {
//        // random operands in range [1..10]
//        a = std::rand() % 10 + 1;
//        b = std::rand() % 10 + 1;
//
//        std::cout << "[" << i << "/" << total << "] " << a << " * " << b << " = ";
//
//        if (!(std::cin >> c)) {
//            std::cout << "Invalid input. Exiting.\n";
//            return 1;
//        }
//
//        if (a * b != c) {
//            ++wrong; // increment wrong answers counter
//            std::cout << "Error! " << a << " * " << b << " = " << (a * b) << "\n";
//        }
//    }
//
//    std::cout << "Count error: " << wrong << "\n";
//
//    return 0;
//}

