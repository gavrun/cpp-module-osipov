#include <iostream>

// by value
void swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// by pointer
void swap_ptr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// by reference
void swap_ref(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// values printer
void vprint(int a, int b) {
    std::cout << "a = " << a << "; b = " << b << '\n';
}

int main() {
    int x = 5, y = 10;

    std::cout << "Initial values:\n";
    vprint(x, y);

    std::cout << "\nSwap by value:\n";
    swap_value(x, y);
    vprint(x, y);  // unchanged

    std::cout << "\nSwap by pointer:\n";
    swap_ptr(&x, &y);
    vprint(x, y);  // swapped

    std::cout << "\nSwap by reference:\n";
    swap_ref(x, y);
    vprint(x, y);  // swapped back

    return 0;
}
