#include <iostream>
#include <utility>

void show_array(const int Arr[], const int N) {
    for (int i = 0; i < N; ++i) std::cout << Arr[i] << ' ';
    std::cout << '\n';
}

bool from_min(const int a, const int b) {
    return a > b;
}
bool from_max(const int a, const int b) {
    return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int, int)) {
    for (int i = 1; i < N; ++i) {
        bool swapped = false;
        for (int j = 0; j < N - i; ++j) {
            if (compare(Arr[j], Arr[j + 1])) {
                std::swap(Arr[j], Arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    const int N = 10;
    int A[N] = { 9, 8, 7, 6, 1, 2, 3, 5, 4, 9 };
    
    int user_choice = 0;

    std::cout << "1. Sort ascending\n";
    std::cout << "2. Sort descending\n";
    std::cin >> user_choice;

    std::cout << "Original: ";
    show_array(A, N);

    // array of function pointers
    bool (*from_f[2])(int, int) = { from_min, from_max };

    if (user_choice >= 1 && user_choice <= 2) {
        // dereference explicitly
        //bubble_sort(A, N, (*from_f[user_choice - 1]));

        // implicit decay (cleaner)
        bubble_sort(A, N, from_f[user_choice - 1]);

        std::cout << "Result:  ";
        show_array(A, N);
    }
    else {
        std::cout << "Unknown option\n";
    }
    return 0;
}

