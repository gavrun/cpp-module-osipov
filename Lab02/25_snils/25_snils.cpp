#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // XXX-XXX-XXX YY - 11 digits

    // sum = d1*9 + d2*8 + ... + d9*1

    // K
    // if sum < 100 then K = sum
    // if sum == 100 or sum == 101 then K = 0
    // if sum > 101 then K = sum % 101, if sum == 100 then K = 0

    // YY <> K

    // input with dashes and spaces supported
    std::string input;

    std::cout << "Enter SNILS (e.g. 123-456-789 01 or 12345678901): ";
    if (!std::getline(std::cin, input)) {
        std::cerr << "Input error\n";
        return 1;
    }

    // remove all non-digit characters
    std::string snils;
    snils.reserve(input.size()); // pre-allocate to avoid reallocations
    for (unsigned char ch : input) {
        if (std::isdigit(ch)) snils.push_back(static_cast<char>(ch));
    }

    // exactly 11 digits
    if (snils.size() != 11) {
        std::cout << "INVALID SNILS\n";
        return 0;
    }

    // split into first 9 and last 2 digits
    std::string digit9 = snils.substr(0, 9);
    std::string digit2 = snils.substr(9, 2);

    // all zeros not valid
    if (digit9 == "000000000") {
        std::cout << "INVALID SNILS\n";
        return 0;
    }

    // weighted sum for the first 9 digits of snils
    int sum = 0;
    
    for (int i = 0; i < 9; ++i) {
        int di = snils[i] - '0';
        int weight = 9 - i; // position weight (first digit *9, ..., last *1)
        sum += di * weight;
    }
    
    // translate sum to checksum 0..99
    int K;
    
    if (sum < 100) {
        K = sum;
    }
    else if (sum == 100 || sum == 101) {
        K = 0;
    }
    else {
        int r = sum % 101;
        K = (r == 100) ? 0 : r;
    }
    
    // format K as two digits with leading zero
    char buf[3];
    std::snprintf(buf, sizeof(buf), "%02d", K);
    std::string expected_code(buf);

    // validate against the last 2 digits of snils
    bool ok = (expected_code == digit2);

    std::cout << (ok ? "VALID SNILS" : "INVALID SNILS") << '\n';

    return 0;
}
