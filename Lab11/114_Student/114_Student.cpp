#include <iostream>
#include <string>
#include <vector>

// Simple representation "name + grade"
struct StudentGrade {
    std::string name;
    char grade;
};

// Container based on std::vector overloaded operator[]
class GradeMap {
private:
    std::vector<StudentGrade> m_map;

public:
    GradeMap() = default;

    char& operator[](const std::string& name) {
        // Find existing student
        for (auto& ref : m_map) {
            if (ref.name == name) {
                return ref.grade; // found - return ref to grade
            }
        }
        // Not found — create new record with empty grade
        StudentGrade tmp{ name, ' ' };
        m_map.push_back(tmp);
        return m_map.back().grade; // ref new grade
    }
};

int main() {
    GradeMap grades;

    grades["John"] = 'A';
    grades["Martin"] = 'B';

    std::cout << "John has a grade of " << grades["John"] << '\n';
    std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

    std::cout << "New name and grade?" << std::endl;
    std::string name;
    char grade;
    std::cin >> name >> grade;

    grades[name] = grade;

    std::cout << name << " has a grade of " << grades[name] << '\n';
    return 0;
}
