#include <iomanip>
#include <cmath>
#include "Time.h"

// Default constructor
Time::Time() : h_(0), m_(0), s_(0) {}

// Value constructor
Time::Time(int hh, int mm, int ss) : h_(hh), m_(mm), s_(ss) {
    if (h_ < 0 || m_ < 0 || s_ < 0) {
        throw TimeError("Negative components are not allowed.");
    }
    normalize_();
}

// Factory from total seconds 
Time Time::from_total_seconds(long long total) {
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
void Time::print() const {
    std::cout
        << std::setw(2) << std::setfill('0') << h_ << ':'
        << std::setw(2) << std::setfill('0') << m_ << ':'
        << std::setw(2) << std::setfill('0') << s_;
}

// Accessors
int Time::hours()   const { return h_; }
int Time::minutes() const { return m_; }
int Time::seconds() const { return s_; }

// Convert to seconds 
long long Time::to_total_seconds_() const {
    return static_cast<long long>(h_) * 3600LL
        + static_cast<long long>(m_) * 60LL
        + static_cast<long long>(s_);
}

// Normalize fields
void Time::normalize_() {
    // convert seconds -> minutes
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

// Operator overloads

// Time + Time
Time operator+(const Time& a, const Time& b) {
    return Time(a.h_ + b.h_, a.m_ + b.m_, a.s_ + b.s_); //raw sum
}

// Time - Time
Time operator-(const Time& a, const Time& b) {
    long long lhs = a.to_total_seconds_();
    long long rhs = b.to_total_seconds_();
    if (lhs < rhs) {
        throw Time::TimeError("Subtraction would lead to negative time.");
    }
    return Time::from_total_seconds(lhs - rhs);
}

// Time + double (seconds)
Time operator+(const Time& t, double secs) {
    long long delta = std::llround(secs); // round to nearest whole second
    long long base = t.to_total_seconds_();
    long long total = base + delta;
    if (total < 0) {
        throw Time::TimeError("Resulting time would be negative.");
    }
    return Time::from_total_seconds(total);
}

// double + Time
Time operator+(double secs, const Time& t) {
    return t + secs; // reuse
}

// Comparisons based on total seconds

bool operator==(const Time& a, const Time& b) {
    return a.to_total_seconds_() == b.to_total_seconds_();
}
bool operator!=(const Time& a, const Time& b) {
    return !(a == b);
}
bool operator<(const Time& a, const Time& b) {
    return a.to_total_seconds_() < b.to_total_seconds_();
}
bool operator<=(const Time& a, const Time& b) {
    return !(b < a);
}
bool operator>(const Time& a, const Time& b) {
    return b < a;
}
bool operator>=(const Time& a, const Time& b) {
    return !(a < b);
}

// Stream output
std::ostream& operator<<(std::ostream& os, const Time& t) {
    // keep same format as print()
    std::streamsize oldw = os.width();
    char oldfill = os.fill();
    os << std::setw(2) << std::setfill('0') << t.h_ << ':'
        << std::setw(2) << std::setfill('0') << t.m_ << ':'
        << std::setw(2) << std::setfill('0') << t.s_;
    os.width(oldw);
    os.fill(oldfill);
    return os;
}

