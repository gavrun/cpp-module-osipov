#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <limits>
#include <cstdint>

class Time {
public:
    // Nested Exception class
    class TimeError : public std::runtime_error {
    public:
        using std::runtime_error::runtime_error;
    };

    // Default constructor
    Time() : h_(0), m_(0), s_(0) {}

    // Value constructor
    Time(int hh, int mm, int ss) : h_(hh), m_(mm), s_(ss) {
        if (h_ < 0 || m_ < 0 || s_ < 0) {
            throw TimeError("Negative components are not allowed.");
        }
        normalize_();
    }

    // Factory from total seconds 
    static Time from_total_seconds(long total) {
        if (total < 0) {
            throw TimeError("Total seconds must be non-negative.");
        }
        int hh = static_cast<int>(total / 3600);
        total %= 3600;
        int mm = static_cast<int>(total / 60);
        int ss = static_cast<int>(total % 60);
        return Time(hh, mm, ss); // ctor normalizes
    }

    // Print in HH:MM:SS format
    void print() const {
        std::cout
            << std::setw(2) << std::setfill('0') << h_ << ':'
            << std::setw(2) << std::setfill('0') << m_ << ':'
            << std::setw(2) << std::setfill('0') << s_;
    }

    // Add two times raw, constructor will normalize
    Time add(const Time& other) const {
        return Time(h_ + other.h_, m_ + other.m_, s_ + other.s_);
    }

    // Subtract two times over factory
    Time sub(const Time& other) const {
        long lhs = to_total_seconds_();
        long rhs = other.to_total_seconds_();
        if (lhs < rhs) {
            throw TimeError("Subtraction would lead to negative time.");
        }
        return from_total_seconds(lhs - rhs);
    }

    int hours()   const { return h_; }
    int minutes() const { return m_; }
    int seconds() const { return s_; }

private:
    int h_;
    int m_;
    int s_;

    // Convert to seconds 
    long to_total_seconds_() const {
        return static_cast<long>(h_) * 3600L
            + static_cast<long>(m_) * 60L
            + static_cast<long>(s_);
    }

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
    try {
        std::cout << std::fixed << std::setprecision(0);
        
        // Create valid 
        std::cout << "t1 = ";
        Time t1(1, 70, 90);  // 02:11:30
        t1.print(); std::cout << "\n";
        std::cout << "t2 = ";
        Time t2(0, 45, 50);  // 00:45:50
        t2.print(); std::cout << "\n";

        std::cout << "sum = ";
        Time sum = t1.add(t2);
        sum.print(); std::cout << "\n";

        // Subtraction ok
        std::cout << "diff = ";
        Time diff = t1.sub(t2);
        diff.print(); std::cout << "\n";

        // Subtraction should throw
        try {
            std::cout << "diff_bad = ";
            Time diff_bad = t2.sub(t1); // second > first
            diff_bad.print(); std::cout << "\n";
        }
        catch (const Time::TimeError& e) {
            std::cerr << "Time error: " << e.what() << "\n";
        }

        // Create invalid
        try {
            std::cout << "t_bad = ";
            Time t_bad(-1, 0, 0);
            std::cout << "\n";
        }
        catch (const Time::TimeError& e) {
            std::cerr << "Time error: " << e.what() << "\n";
        }
    }
    catch (const Time::TimeError& e) {
        std::cerr << "Time error: " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << "\n";
        return 2;
    }
    return 0;
}
