#pragma once

#include <iostream>
#include <stdexcept>

class Time
{
public:
    // Nested Exception class
    class TimeError : public std::runtime_error {
    public:
        using std::runtime_error::runtime_error;
    };

    Time();
    Time(int hh, int mm, int ss);
        
    static Time from_total_seconds(long long total);

    void print() const;

    int hours() const;
    int minutes() const;
    int seconds() const;

    friend Time operator+(const Time& a, const Time& b);
    friend Time operator-(const Time& a, const Time& b);
    friend Time operator+(const Time& t, double secs);
    friend Time operator+(double secs, const Time& t);

    friend bool operator==(const Time& a, const Time& b);
    friend bool operator!=(const Time& a, const Time& b);
    friend bool operator<(const Time& a, const Time& b);
    friend bool operator<=(const Time& a, const Time& b);
    friend bool operator>(const Time& a, const Time& b);
    friend bool operator>=(const Time& a, const Time& b);

    friend std::ostream& operator<<(std::ostream& os, const Time& t);

private:
    int h_;
    int m_;
    int s_;

    long long to_total_seconds_() const;
    void normalize_();
};

