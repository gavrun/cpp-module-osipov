#include <iostream>
#include <vector>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    int a, b, c;
    int k = 0;

    const int n = 10;
    int mas[n];                 // all answers

    std::vector<int> v_correct; // correct answers
    std::vector<int> v_wrong;   // wrong answers

    for (int i = 0; i < n; ++i) {
        a = std::rand() % 10 + 1;
        b = std::rand() % 10 + 1;

        // question
        std::cout << a << " * " << b << " = ";
        // answer
        std::cin >> c;

        mas[i] = c; // store answer into array

        // answered wrong?
        if (a * b != c) {
            v_wrong.push_back(c); // wrong -> Bad
            ++k;
            std::cout << "Error! " << a << " * " << b << " = " << (a * b) << "\n";
        }
        else {
            v_correct.push_back(c); // right -> Good
        }
    }

    // all entered answers (array)
    std::cout << "\nAll: ";
    for (int i = 0; i < n; ++i) std::cout << mas[i] << ' ';
    std::cout << "\n";

    // correct answers (vector correct)
    std::cout << "Good: ";
    for (std::size_t i = 0; i < v_correct.size(); ++i) std::cout << v_correct[i] << ' ';
    std::cout << "\n";

    // wrong answers (vector wrong)
    std::cout << "Bad:  ";
    for (std::size_t i = 0; i < v_wrong.size(); ++i) std::cout << v_wrong[i] << ' ';
    std::cout << "\n";

    std::cout << "Count error: " << k << "\n";

    return 0;
}

