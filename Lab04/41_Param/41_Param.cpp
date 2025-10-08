#include <iostream>

// by value
void fum_value(double k, double x, double y) {
    x = x + k;
    y = y + k;
}

// by pointer
void fum_ptr(double k, double* x, double* y) {
    *x = *x + k;
    *y = *y + k;
}

// by reference
void fum_ref(double k, double& x, double& y) {
    x = x + k;
    y = y + k;
}

// values printer
void vprint(double x, double y) {
    std::cout << "x = " << x << "; y = " << y << '\n';
}

int main() {
    double k = 2.5;
    double xv = 10.0;
    double yv = 10.0;

    vprint(xv, yv);                 // initial values

    fum_value(k, xv, yv);          // pass-by-value: no external changes
    vprint(xv, yv);                 // still 10, 10

    fum_ptr(k, &xv, &yv);          // pass-by-pointer: changes apply
    vprint(xv, yv);                 // now 12.5, 12.5

    fum_ref(k, xv, yv);            // pass-by-reference: changes apply
    vprint(xv, yv);                 // now 15, 15

    return 0;
}
