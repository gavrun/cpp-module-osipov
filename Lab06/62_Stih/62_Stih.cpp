#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Alternate scenario
    // read from text file instead of typing multiline on keyboard
    std::cout << "Read file mode.\n";
    std::cout << "Enter local filename to read (press Enter to skip and input text manually): ";
    std::string inputFile;
    std::getline(std::cin, inputFile);

    std::string rawText; // will hold all read lines (optional)
    bool readSuccess = false;

    // try to read from existing file
    if (!inputFile.empty()) {
        std::ifstream in(inputFile);
        if (in.is_open()) {
            std::cout << "Reading text from file '" << inputFile << "'...\n";
            std::string line;
            while (std::getline(in, line)) {
                rawText += line + '\n'; // collect text
            }
            in.close();
            readSuccess = true;
            std::cout << "File read successfully.\n";
        }
        else {
            std::cerr << "Failed to open file: " << inputFile << "\n";
        }
    }

    // Main scenario
    // if we didn not read from file, switch to manual input
    if (!readSuccess) {
        std::cout << "Manual input mode.\n";
        std::cout << "Enter output filename (press Enter for default 'manual.txt'): ";
        std::string outputFile;
        std::getline(std::cin, outputFile);
        if (outputFile.empty()) outputFile = "manual.txt";

        std::ofstream out(outputFile, std::ios::out | std::ios::trunc);
        if (!out.is_open()) {
            std::cerr << "Failed to open file for writing: " << outputFile << "\n";
            return 1;
        }

        std::cout << "Type your text. Submit an empty line to finish.\n";

        while (true) {
            std::string line;
            if (!std::getline(std::cin, line)) { // input error or EOF
                std::cerr << "Input error.\n";
                break;
            }
            if (line.empty()) break;             // stop on empty line
            out << line << '\n';
            if (!out) {
                std::cerr << "Write error.\n";
                return 1;
            }
        }

        out.close();
        std::cout << "Saved to '" << outputFile << "'.\n";
    }
    else {
        // If the file was successfully read, we can print it for confirmation
        std::cout << "\n--- Text content ---\n";
        std::cout << rawText;
        std::cout << "--------------------\n";
    }

    return 0;
}

