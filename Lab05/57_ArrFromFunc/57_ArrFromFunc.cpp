#include <iostream>

int* max_vect(int kc, const int* a, const int* b) {
    if (kc < 0) kc = 0; // guard, though kc should be >= 0
    
    int* c = new int[kc]; // caller will delete[] c
    
    for (int i = 0; i < kc; ++i)
        c[i] = (a[i] > b[i]) ? a[i] : b[i];
    
    return c;
}

int main() {
    using std::cout;

    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };

    // count elements
    int kc = sizeof(a) / sizeof(a[0]);
    // create pointer and get result array
    int* c = max_vect(kc, a, b);

    // print
    for (int i = 0; i < kc; i++)       
        cout << c[i] << " ";
    cout << "\n";

    delete[] c; // free memory
    return 0;
}
