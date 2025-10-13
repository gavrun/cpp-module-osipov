#include <iostream>
#include <limits>

// Time interval struct
struct Time {
    int hours{ 0 };
    int minutes{ 0 };
    int seconds{ 0 };

    // Normalize minutes/seconds into [0..59] and adjust hours
    void normalize() {
        // fix seconds overflow/underflow
        if (seconds >= 60 || seconds < 0) {
            int carry = seconds / 60; // in C++ negative divides toward zero
            // correct carry for negative seconds not multiple of 60
            if (seconds < 0 && seconds % 60 != 0) --carry;
            seconds -= carry * 60;
            minutes += carry;
        }

        // fix minutes overflow/underflow
        if (minutes >= 60 || minutes < 0) {
            int carry = minutes / 60;
            if (minutes < 0 && minutes % 60 != 0) --carry;
            minutes -= carry * 60;
            hours += carry;
        }

        // treat time as interval (hours must not be negative)
        if (hours < 0) {
            // floor - zero interval
            hours = 0; minutes = 0; seconds = 0;
        }
    }

    // Convert to total seconds
    long to_seconds() const {
        return static_cast<long>(hours) * 3600L
            + static_cast<long>(minutes) * 60L
            + static_cast<long>(seconds);
    }

    // Build from total seconds
    static Time from_seconds(long total) {
        if (total < 0) total = 0;
        Time t;
        t.hours = static_cast<int>(total / 3600);
        total %= 3600;
        t.minutes = static_cast<int>(total / 60);
        t.seconds = static_cast<int>(total % 60);
        return t;
    }

    // Add interval
    Time add(const Time& other) const {
        return from_seconds(this->to_seconds() + other.to_seconds());
    }

    // Subtract interval (floor at 0)
    Time sub(const Time& other) const {
        long a = this->to_seconds();
        long b = other.to_seconds();
        return from_seconds(a - b);
    }

    // Pretty print HH:MM:SS
    void print() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << '\n';
    }
};

// Read Time from stdin
Time read_time(const char* label) {
    Time t;
    std::cout << "Enter hours, minutes, seconds for " << label << " (format HH MM SS space-separated): ";
    std::cin >> t.hours >> t.minutes >> t.seconds;

    // invalid input, clear and set zero
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        t = Time{};
    }

    // numbers off, normalize
    t.normalize();

    return t;
}

int main() {
    // labels
    const char* tl = "Time T";
    const char* tl2 = "Time Tdt";

    // read time "T"
    Time t = read_time(tl);

    // show total seconds
    std::cout << "Total seconds of T = " << t.to_seconds() << "\n";

    // add/sub time interval "T delta"
    Time t2 = read_time(tl2);
    Time sum = t.add(t2);
    Time diff = t.sub(t2);

    std::cout << tl << " = "; t.print();
    std::cout << tl2 << " = "; t2.print();
    std::cout << tl << " + " << tl << " = "; sum.print();
    std::cout << tl << " - " << tl << " = "; diff.print();

    return 0;
}
