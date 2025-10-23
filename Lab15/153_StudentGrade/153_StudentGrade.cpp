#include <iostream>
#include <string>
#include <map>

using Grades = std::map<std::string, char>;

struct StudentGrade {
    std::string name;
    char grade;
};

// print all grades
void print_grades(const Grades& g) {
    for (const auto& [name, grade] : g) {
        std::cout << name << " -> " << grade << '\n';
    }
}

// get grade by name
char get_grade_or_zero(const Grades& g, const std::string& name) {
    auto it = g.find(name);
    return (it == g.end()) ? '\0' : it->second;
}


int main()
{
    Grades grades;

    grades["Ivan"] = 'A';
    grades["Maria"] = 'B';

    std::cout << "Current grades:\n";
    print_grades(grades);

    std::cout << "\nEnter name and grade (e.g. Petr A) or skip (^Z + Enter): ";
    std::string name;
    char grade;

    if (std::cin >> name >> grade) {
        grades[name] = grade;
        std::cout << "\nAfter update:\n";
        print_grades(grades);
    }
    else {
        std::cout << "\nSkipped adding new student.\n";
    }

    std::cout << "\nLookup name: ";
    std::string query;
    if (std::cin >> query) {
        if (char g = get_grade_or_zero(grades, query)) {
            std::cout << query << " has a grade of " << g << '\n';
        }
        else {
            std::cout << "No grade for " << query << '\n';
        }
    }

    return 0;
}
