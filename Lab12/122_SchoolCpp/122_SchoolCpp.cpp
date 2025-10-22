#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"

int main()
{
    // test scores
    std::vector<int> scores;

    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    //std::vector<int> scores = { 5, 3, 4, 4, 5, 3, 3, 3, 3 };


    // read scores from std::cin

    //student stud("Petrov", "Ivan", "Alexeevich", scores);

    // dynamic
    student* stud = new student("Petrov", "Ivan", "Alexeevich", scores);

    std::cout << stud->get_full_name() << '\n';
    std::cout << "Average score: " << stud->get_average_score() << '\n';

    delete stud;

    return 0;
}
