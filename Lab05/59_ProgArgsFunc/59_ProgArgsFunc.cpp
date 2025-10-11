#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>

constexpr int kExpectArgCount = 4;

enum Operation {
    kAdd,
    kMultiply
};

void printUsage(const char* progName) {
    std::cerr << "Usage:\n"
              << "  " << progName << " -a <int> <int>   # sum\n"
              << "  " << progName << " -m <int> <int>   # multiply\n";
}

bool tryParseOperation(const char* flag, Operation& op) {
    // Accept flag
    if (std::strncmp(flag, "-a", 2) == 0) {
        op = kAdd;
        return true;
    }
    if (std::strncmp(flag, "-m", 2) == 0) {
        op = kMultiply;
        return true;
    }
    // Reject unsupported flag
    return false;
}

bool tryParseInt(const char* text, int& value) {
    // Reset errno prior to conversion to detect range errors
    errno = 0;
    char* end = nullptr;
    const long parsed = std::strtol(text, &end, 10);
    // Reject inputs that do not fully consume the string
    if (end == text || *end != '\0') {
        return false;
    }
    // Commit
    value = static_cast<int>(parsed);
    return true;
}

long computeResult(Operation op, int lhs, int rhs) {
    switch (op) {
        case kAdd:
            return static_cast<long>(lhs) + static_cast<long>(rhs);
        case kMultiply:
            return static_cast<long>(lhs) * static_cast<long>(rhs);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    // Check required arguments count
    if (argc < kExpectArgCount) {
        std::cerr << "Error: not enough arguments.\n";
        printUsage(argv[0]);
        return 1;
    }

    Operation op = kAdd; // default before parsing
    // printUsage(argv[0]);
    
    // Parse the operation selector flag.
    if (!tryParseOperation(argv[1], op)) {
        std::cerr << "Error: unknown flag '" << argv[1] << "'. Use -a or -m.\n";
        return 1;
    }

    // Validate left-hand right-hand operands
    int lhs = 0;
    if (!tryParseInt(argv[2], lhs)) {
        std::cerr << "Error: '" << argv[2] << "' is not a valid integer.\n";
        return 1;
    }
    int rhs = 0;
    if (!tryParseInt(argv[3], rhs)) {
        std::cerr << "Error: '" << argv[3] << "' is not a valid integer.\n";
        return 1;
    }

    // Print result
    std::cout << "Result:\t" << computeResult(op, lhs, rhs) << "\n";
    
    return 0;
}
