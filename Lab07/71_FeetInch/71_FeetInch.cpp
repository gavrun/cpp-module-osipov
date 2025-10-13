#include <iostream>
#include <windows.h>

struct Distance {
    int feet;
    double inches;

    // member method to print itself
    void ShowDist() const {
        std::cout << feet << "\'-" << inches << "\"\n"; // not formatted, not normalized
    }
};

Distance AddDist(Distance d1, Distance d2) {
    Distance d;

    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;

    while (d.inches >= 12.0) {
        d.inches -= 12.0;
        ++d.feet;
    }

    return d;
}

Distance InputDist() {
    Distance d{};

    std::cout << "\nInput feet: ";
    std::cin >> d.feet;

    std::cout << "Input inches: ";
    std::cin >> d.inches;

    return d;
}

int main() {
    Distance d1 = InputDist();
    Distance d2 = { 1, 6.25 };
    Distance d3 = AddDist(d1, d2);

    // call member version
    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();

    return 0;
}

