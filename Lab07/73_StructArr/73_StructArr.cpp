#include <iostream>
#include <windows.h>

struct Distance {
    int feet;
    double inches;

    void ShowDist() const {
        std::cout << feet << "\'-" << inches << "\"\n"; // not formatted, not normalized
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
    std::cout << "Struct Distance (feet/inches).\n";
    Distance d1 = InputDist();
    Distance d2 = { 1, 6.25 };
    Distance d3 = AddDist(d1, d2);

    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();

    int n;
    std::cout << "Enter array size for Distances: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid size\n";
        return 1;
    }

    Distance* masDist = new Distance[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "\nEnter for item number" << i + 1 << ": ";
        masDist[i] = InputDist();
    }

    std::cout << "\n\nArray of Distances:\n";
    for (int i = 0; i < n; ++i) {
        masDist[i].ShowDist();
    }

    Distance total{ 0, 0.0 };
    for (int i = 0; i < n; ++i) {
        total = AddDist(total, masDist[i]);
    }
    
    std::cout << "\nTotal: ";
    total.ShowDist(); // prints raw 15'-8"

    return 0;
}
