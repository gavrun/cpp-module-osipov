#include <iostream>
#include <utility>

// printer 
void show_array(const int Arr[], const int N) {
    for (int i = 0; i < N; ++i) std::cout << Arr[i] << ' ';
    std::cout << '\n';
}

// compare functions
// return true if a should go after b -> swap to get ascending : descending
bool from_min(const int a, const int b) {
    return a > b; 
}
bool from_max(const int a, const int b) {
    return a < b;
}

// bubble sort with function pointer comparator
void bubble_sort(int Arr[], const int N, bool (*compare)(int, int)) {
    for (int i = 1; i < N; ++i) {
        bool swapped = false; // optimization
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

    // raw choice 1 or 2
    int user_choice = 0;

    // menu and input
    std::cout << "1. Sort ascending\n";
    std::cout << "2. Sort descending\n";
    std::cin >> user_choice;

    std::cout << "Original: ";
    show_array(A, N);

    // switch-based dispatch
    switch (user_choice) {
    case 1: bubble_sort(A, N, from_min); break;
    case 2: bubble_sort(A, N, from_max); break;
    default:
        std::cout << "Unknown option\n";
        return 0;
    }

    std::cout << "Result:  ";
    show_array(A, N);

    return 0;
}

