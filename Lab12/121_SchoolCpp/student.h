#pragma once

#include "human.h"
#include <vector>
#include <numeric>

class student :
    public human
{
public:
    // pass scores by value
    student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores)
        : human(std::move(last_name), std::move(name), std::move(second_name)), scores_(std::move(scores)) {
    }

    float get_average_score() const {
        const unsigned count = static_cast<unsigned>(scores_.size());
        
        // empty vector (student with no scores)
        if (count == 0) return 0.0f;

        unsigned sum = std::accumulate(scores_.begin(), scores_.end(), 0u);

        return static_cast<float>(sum) / static_cast<float>(count);
    }

private:
    std::vector<int> scores_;
};

