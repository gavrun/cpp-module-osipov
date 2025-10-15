#include <iostream>
#include <string>

class Student {
public:
    // Nested exception class to carry error context
    class ExScore {
    public:
        std::string origin; // function where the error happened
        int iValue;    // invalid score value
        ExScore(std::string orign, int sc) : origin(orign), iValue(sc) {}
    };

    void set_name(const std::string& n) { name = n; }
    void set_last_name(const std::string& ln) { last_name = ln; }

    void set_scores(const int student_scores[5]) {
        for (int i = 0; i < 5; ++i) {
            if (student_scores[i] > 5) {
                // Generate exception object with context + bad value
                throw ExScore("in set_scores()", student_scores[i]);
            }
            scores[i] = student_scores[i];
        }
    }

    void calculate_average_score() {
        int sum = 0;
        for (int i = 0; i < 5; ++i) sum += scores[i];
        average_score = sum / 5.0; 
    }

    void print() const {
        std::cout << "Student: " << name << ' ' << last_name << "\nScores: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << scores[i] << (i < 4 ? ' ' : '\n');
        }
        std::cout << "Average: " << average_score << "\n";
    }

private:
    std::string name;
    std::string last_name;
    int scores[5]{};
    double average_score{};
};

int main() {
    Student s;

    std::cout << "Enter first name and last name:\n";
    std::string name, last_name;
    std::cin >> name >> last_name;
    s.set_name(name);
    s.set_last_name(last_name);

    std::cout << "Enter 5 integer scores (each 0..5):\n";
    int scores[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> scores[i];
    }

    try {
        // Potentially throws if any score > 5
        s.set_scores(scores);
        s.calculate_average_score();
        s.print();
    }
    catch (Student::ExScore& ex) {
        std::cout << "\nInitialization error " << ex.origin
             << "\nThe entered score value " << ex.iValue
             << " is not allowed.\n";
    }

    return 0;
}
