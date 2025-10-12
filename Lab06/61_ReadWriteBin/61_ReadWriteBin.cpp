#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    // Data and sum
    double sum = 0.0;
    const int n = 100;
    double nums[n];

    // Seed PRNG
    // srand(time(NULL));
    std::srand(static_cast<unsigned>(std::time(nullptr))); 

    // Fill array with random values in [0;99]
    for (int i = 0; i < n; ++i) {
        nums[i] = std::rand() % 100; // integers stored as doubles
    }

    // Write to a binary file
    std::ofstream out("test.bin", std::ios::binary); // ios::out is implied
    if (!out) {
        std::cout << "Something happened\n";
        return 1; // early exit on failure
    }

    // Dump raw bytes of the array
    // C-style (char*) casts interation vs. C++-style deliberate reinterpret_cast to char*
    out.write(reinterpret_cast<const char*>(nums), sizeof(nums)); 
    out.close(); // flush + close

    // Read from the same file (to the same buffer)
    std::ifstream in("test.bin", std::ios::binary);
    if (!in) {
        std::cout << "Something happened\n";
        return 1;
    }

    // Read exact same amount
    in.read(reinterpret_cast<char*>(nums), sizeof(nums));
    in.close();

    // Process data (sum and print)
    const int k = static_cast<int>(sizeof(nums) / sizeof(double));
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
        std::cout << nums[i] << ' ';
    }
    std::cout << "\nsum = " << sum << std::endl;

    return 0;
}
