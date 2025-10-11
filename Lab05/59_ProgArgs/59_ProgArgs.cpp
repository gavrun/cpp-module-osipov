#include <iostream>
#include <cstring>
#include <cstdlib>

/*
 CLI tool: 
   -a for addition
   -m for multiplication
 
 Requirement:
   require 1 program name + 2 flag + 3 operand + 4 operand
 Usage: 
   prog -a 12 45
   prog -m 12 45
*/

int main(int argc, char* argv[]) {
    // Check argument count
    if (argc < 4) {
        std::cerr << "Error: not enough arguments.\n";
        std::cerr << "Usage:\n"
            << "  " << argv[0] << " -a <int> <int>   # sum\n"
            << "  " << argv[0] << " -m <int> <int>   # multiply\n";
        return 1;
    }

    // Check flag format
    const char* flag = argv[1];
    bool add = (std::strncmp(flag, "-a", 2) == 0);
    bool mul = (std::strncmp(flag, "-m", 2) == 0);
    if (!add && !mul) {
        std::cerr << "Error: unknown flag '" << flag << "'. Use -a or -m.\n";
        return 1;
    }

    // Convert operands
    int a = std::atoi(argv[2]);
    int b = std::atoi(argv[3]);
    // NOTE: 
    // If conversion fails, it returns 0, which is indistinguishable from a real 0 input.
    // In production code prefer strtol for robust validation.

    // Operate
    long result = 0;
    if (add) {
        result = static_cast<long>(a) + static_cast<long>(b);
    }
    else { // mul
        result = static_cast<long>(a) * static_cast<long>(b);
    }

    // Print result
    std::cout << "Result:\t" << result << "\n";

    return 0;
}

