#include <iostream>
#include <memory>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
    std::cout << "Hello School!\n";

    // Test scores
    std::vector<int> scores{ 5,3,4,4,5,3,3,3,3 };
    
    // Test workload hours
    unsigned int teacher_work_time = 40;
    
    // Test people
    std::vector<std::unique_ptr<human>> people;
    people.emplace_back(std::make_unique<student>("Petrov", "Ivan", "Alexeevich", scores));
    people.emplace_back(std::make_unique<teacher>("Sergeev", "Dmitri", "Sergeevich", teacher_work_time));

    // polymorphic methods
    for (const auto& p : people) {
        std::cout << p->role() << ": ";
        p->print(std::cout);
        std::cout << '\n';
    }

    return 0;
}

