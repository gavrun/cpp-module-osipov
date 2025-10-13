#include "Student.h"

// Constructor 
Student::Student(std::string name, std::string last_name) {
    Student::set_name(name);
    Student::set_last_name(last_name);
}

// Set first name
void Student::set_name(const std::string& student_name) {
    name = student_name;
}

// Get first name
std::string Student::get_name() const {
    return name;
}

// Set last name
void Student::set_last_name(const std::string& student_last_name) {
    last_name = student_last_name;
}

// Get last name
std::string Student::get_last_name() const {
    return last_name;
}

// Set five intermediate scores
void Student::set_scores(const int student_scores[5]) {
    for (int i = 0; i < 5; ++i) {
        scores[i] = student_scores[i];
    }
}

// Set precomputed average score
void Student::set_average_score(double avg) {
    average_score = avg;
}

// Get current average score
double Student::get_average_score() const {
    return average_score;
}

// Calculate and store average internally
void Student::calculate_average_score() {
    int sum = 0;
    for (int i = 0; i < 5; ++i) sum += scores[i];
    average_score = sum / 5.0; // force double
}

