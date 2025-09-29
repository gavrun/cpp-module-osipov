#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // coin change (greedy)
    
    // Russian coins denominations in 2025
    // 10, 5, 2, 1 ruble
    // 50, 10, 5, 1 kopeek

    // all in kopeek for simplicity 1000, 500, 200, 100, 50, 10, 5, 1

    // 'long long' for amount of money in kopeek
    long long amount = 0;

    // input amount
    std::cout << "Enter amount in 'kopeek' (non-negative number): ";
    if (!(std::cin >> amount)) {
        std::cerr << "Input error\n";
        return 1;
    }

    // validate amount
    if (amount < 0) {
        std::cout << "Amount must be non-negative.\n";
        return 0;
    }

    // zero calculations
    if (amount == 0) {
        std::cout << "0 coins\n";
        return 0;
    }

    // 'int' for single coin value
    const std::vector<int> coins = { 1000, 500, 200, 100, 50, 10, 5, 1 };

    long long remaining = amount;

    long long total_coins = 0; // minimal number of coins

    std::cout << "Breakdown:\n";

    for (int coin : coins) {
        long long cnt = remaining / coin;

        if (cnt > 0) {
            if (coin >= 100) {
                std::cout << (coin / 100) << " ruble coin(s): " << cnt << '\n';
            }
            else {
                std::cout << coin << " kopeck coin(s): " << cnt << '\n';
            }
            total_coins += cnt;
            remaining %= coin;
        }
        // (cnt == 0) move to the smaller coin denomination
    }

    std::cout << "Total coins: " << total_coins << '\n';

    return 0;
}

