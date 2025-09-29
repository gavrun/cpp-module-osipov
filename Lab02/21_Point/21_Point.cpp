#include <iostream>

using namespace std;

int main()
{
    cout << "Shape half/circle x(-3; 3) y(0; 3)\n";

    double x, y;
    cout << "Input points x and y: ";
    cin >> x >> y;

    if (x * x + y * y < 9 && y > 0) {
        cout << "inside\n";
    }
    else if (x * x + y * y > 9 || y < 0) {
        cout << "outside\n";
    }
    else {
        cout << "border\n";
    }

    return 0;
}
