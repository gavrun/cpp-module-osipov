#include <iostream>
#include <string>
#include "student.h"

int main() {
    // Create dynamic object

    std::string name;
    std::string last_name;

    // Read
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);

    Student* student01 = new Student(name, last_name);

    // Grade marks
    int scores[5];
    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << (i + 1) << ": ";
        std::cin >> scores[i];

        // [2..5] range hint
        if (scores[i] < 2 || scores[i] > 5) {
            std::cout << "NOTE: student mark is usually between 2 and 5\n";
        }

        sum += scores[i];
    }

    // Clear input state/newline
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Store data in object via pointer

    student01->set_scores(scores);

    double average_score = sum / 5.0;
    student01->set_average_score(average_score);

    // student01.calculate_average_score();

    std::cout << "Average score for "
        << student01->get_name() << " "
        << student01->get_last_name() << " is "
        << student01->get_average_score() << std::endl;

    // destructor -> save() via RAII
    delete student01;

    return 0;
}

