#include <iostream>
#include <string>

class Student {
public:
    void set_name(const std::string& student_name) { name = student_name; }

    std::string get_name() const { return name; }

    void set_last_name(const std::string& student_last_name) { last_name = student_last_name; }

    std::string get_last_name() const { return last_name; }

    void set_scores(const int student_scores[5]) {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
    }

    void set_average_score(double avg) { average_score = avg; }

    double get_average_score() const { return average_score; }

    void calculate_average_score() {
        int sum = 0;
        for (int i = 0; i < 5; ++i) sum += scores[i];
        average_score = sum / 5.0; // force double
    }

private:
    // five midterm scores
    int scores[5]{};
    
    double average_score{};
   
    std::string name;
    std::string last_name;
};

int main() {
    Student student01;

    std::string name;
    std::string last_name;

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Last name: ";
    std::getline(std::cin, last_name);

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

    student01.set_name(name);
    student01.set_last_name(last_name);
    student01.set_scores(scores);

    double average_score = sum / 5.0;
    student01.set_average_score(average_score);

    // student01.calculate_average_score();

    std::cout << "Average score for " << student01.get_name() << " "
        << student01.get_last_name() << " is "
        << student01.get_average_score() << std::endl;

    return 0;
}
