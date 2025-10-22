#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

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

    // test workload hours
    unsigned int teacher_work_time = 40;

    // read scores from std::cin

    student stud("Petrov", "Ivan", "Alexeevich", scores);
    std::cout << stud.get_full_name() << '\n';
    std::cout << "Average score: " << stud.get_average_score() << '\n';

    teacher tchr("Sergeev", "Dmitri", "Sergeevich", teacher_work_time);
    std::cout << tchr.get_full_name() << std::endl;
    std::cout << "Average hours: " << tchr.get_work_time() << std::endl;

    // dynamic
    //student* stud = new student("Petrov", "Ivan", "Alexeevich", scores);
    //std::cout << stud->get_full_name() << '\n';
    //std::cout << "Average score: " << stud->get_average_score() << '\n';
    
    //teacher* tchr = new teacher("Sergeev", "Dmitri", "Sergeevich", teacher_work_time);
    //std::cout << tchr->get_full_name() << std::endl;
    //std::cout << "Average hours: " << tchr->get_work_time() << std::endl;

    //delete tchr;
    //delete stud;

    return 0;
}
