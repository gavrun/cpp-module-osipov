#include <iostream>
#include <string>
#include "Student.h"
#include "IdCard.h"

int main() {
    // Create dynamic object

    std::string name;
    std::string last_name;
    int cardNumber = 0;
    std::string cardCategory;

    // Read
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "IdCard number: ";
    std::cin >> cardNumber;
    std::cout << "IdCard category: ";
    std::cin >> std::ws; // eat leftover newline
    std::getline(std::cin, cardCategory);

    //IdCard idc(cardNumber, cardCategory);

    //Student* student02 = new Student(name, last_name, &idc);
    Student* student02 = new Student(name, last_name, cardNumber, cardCategory);

    // Print id card
    //std::cout << student02->get_name() << " has IdCard: " << student02->get_id_card().get_number() << '\n';
    //std::cout << student02->get_name() << " has Category: " << student02->get_id_card().get_category() << '\n';

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

    student02->set_scores(scores);
    student02->set_average_score(sum / 5.0);

    // student01.calculate_average_score();

    //std::cout << "Average score for "
    //    << student02->get_name() << " "
    //    << student02->get_last_name() << " is "
    //    << student02->get_average_score() << std::endl;

    student02->display();

    // destructor -> save() via RAII
    delete student02;

    return 0;
}

