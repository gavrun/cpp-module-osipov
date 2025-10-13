#include <iostream>
#include <iomanip>
#include <stdexcept>

class Time {
public:
    // Default constructor
    Time() : h_(0), m_(0), s_(0) {}

    // Value constructor
    Time(int hh, int mm, int ss) : h_(hh), m_(mm), s_(ss) {
        normalize_(); // bring to canonical form
    }

    // Print in HH:MM:SS format
    void print() const {
        std::cout 
            // leading zeros
            << std::setw(2) << std::setfill('0') << h_ << ':'
            << std::setw(2) << std::setfill('0') << m_ << ':'
            << std::setw(2) << std::setfill('0') << s_;
    }

    // Add time objects
    Time add(const Time& other) const {
        // Construct with raw sum; constructor will normalize
        return Time(h_ + other.h_, m_ + other.m_, s_ + other.s_);
    }

    int hours() const { return h_; }
    int minutes() const { return m_; }
    int seconds() const { return s_; }

private:
    int h_;
    int m_;
    int s_;

    // Normalize fields
    void normalize_() {
        // first convert seconds to minutes
        if (s_ >= 60) {
            m_ += s_ / 60;
            s_ = s_ % 60;
        }
        // carry minutes -> hours
        if (m_ >= 60) {
            h_ += m_ / 60;
            m_ = m_ % 60;
        }
    }
};

int main() {
    // Two times objects initialize -> normalize
    const Time t1(1, 70, 90);  // 2:11:30
    const Time t2(0, 45, 50);  // 0:45:50

    // Another default
    Time t3;

    t3 = t1.add(t2);

    // Print all three
    std::cout << "Object 't1' = "; t1.print(); std::cout << '\n';
    std::cout << "Object 't2' = "; t2.print(); std::cout << '\n';
    std::cout << "Object 't3' = "; t3.print(); std::cout << '\n';

    return 0;
}
