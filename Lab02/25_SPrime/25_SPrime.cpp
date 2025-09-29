#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>


// Sieve of Eratosthenes 
// input maximum number 'n'
// output bool array true if x is prime, false otherwise
static std::vector<uint8_t> sieve_up_to(long long n) {
    // array of 'true', assume all numbers are prime 
    std::vector<uint8_t> is_prime(n + 1, true);

    // skip 0 and 1 not prime
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    // composite check
    for (long long p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            // from p*p as smaller multiples already handled by smaller primes
            for (long long q = p * p; q <= n; q += p) {
                is_prime[q] = false;
            }
        }
    }

    return is_prime;
}

// Superprime check
// input number 'n'
// output bool true if prime and its index among primes is also prime
static bool is_superprime(long long n) {
    // skip numbers less than 2
    if (n < 2) return false;

    // sieve up to n
    auto prime = sieve_up_to(n);

    // n itself must be prime
    if (!prime[n]) return false;

    // count index of n among all primes
    long long index = 0;
    for (long long x = 2; x <= n; x++) {
        if (prime[x]) index++;
    }

    // check if index itself is prime
    if (index < 2) return false;

    // check using trial division
    for (long long d = 2; d * d <= index; d++) {
        if (index % d == 0) return false;
    }

    // passed all tests, n is superprime
    return true;
}

int main() {
    std::ios::sync_with_stdio(false); // turn off C I/O sync
    std::cin.tie(nullptr); // untie cin from cout

    // 'long long' for input to support large values
    long long n;

    std::cout << "Enter n: ";
    if (!(std::cin >> n)) {
        std::cerr << "Input error\n";
        return 1;
    }

    bool answer = is_superprime(n);

    std::cout << (answer ? "YES (superprime)" : "NO (not superprime)") << "\n";

    return 0;
}
