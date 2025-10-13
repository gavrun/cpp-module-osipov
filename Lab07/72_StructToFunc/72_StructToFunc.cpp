#include <iostream>
#include <windows.h>

struct Distance {
    int feet;
    double inches;

    void ShowDist() const {
        std::cout << feet << "\'-" << inches << "\"\n";
    }
};

// by const reference
Distance AddDist(const Distance& d1, const Distance& d2) {
    Distance d;

    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;

    while (d.inches >= 12.0) {
        d.inches -= 12.0;
        ++d.feet;
    }

    return d; // returned by value, NRVO
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

    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();

    return 0;
}
