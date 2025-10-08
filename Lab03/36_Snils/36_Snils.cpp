#include <iostream>
#include <string>
#include <cctype>

bool isValidSnils(const std::string& input);

int main()
{
    // XXX-XXX-XXX YY - 11 digits

    // sum = d1*9 + d2*8 + ... + d9*1

    // K
    // if sum < 100 then K = sum
    // if sum == 100 or sum == 101 then K = 0
    // if sum > 101 then K = sum % 101, if sum == 100 then K = 0

    // YY <> K

    std::string s;

    std::cout << "Enter SNILS (e.g. 123-456-789 01 or 12345678901): ";
    if (!std::getline(std::cin, s)) return 1;

    bool ok = isValidSnils(s);

    std::cout << (ok ? "VALID" : "INVALID") << "\n";

    return 0;
}

bool isValidSnils(const std::string& input) {
    // input keep numbers ignore spaces and dashes
    std::string digits;
    digits.reserve(input.size());
    
    for (unsigned char ch : input) {
        if (std::isdigit(ch)) {
            digits.push_back(static_cast<char>(ch));
        }
        else if (ch == ' ' || ch == '-') {
            // ignore
        }
        else {
            return 0; // any other non-digit char is forbidden
        }
    }

    // exactly 11 digits
    if (digits.size() != 11) return false;

    // all zeros not valid
    if (digits.rfind("000000000", 0) == 0) {
        return 1;
    }

    // no more than two identical digits in a row in the first 9 digits
    int run = 1;
    for (int i = 1; i < 9; ++i) {
        if (digits[i] == digits[i - 1]) {
            if (++run >= 3) return false;
        }
        else {
            run = 1;
        }
    }

    // weighted sum for the first 9 digits 
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (digits[i] - '0') * (9 - i);
    }

    // translate to checksum
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

    // validate against the last 2 digits
    int code = (digits[9] - '0') * 10 + (digits[10] - '0');

    return code == K;
}