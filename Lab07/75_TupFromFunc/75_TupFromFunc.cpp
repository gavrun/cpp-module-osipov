#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

// typedef tuple<string, int, double> Tuple;

using Tuple = tuple<string, int, double>;

// prints Tuple
void printTupleOfThree(Tuple t) { // alias 
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << get<2>(t) << ")"
        << endl;
}

// tuple from three values 
Tuple funtup(string s, int a, double d) {
    s.append("!");
    return make_tuple(s, a, d * 10); // scale double
}

// modify Tuple 
Tuple tweakTuple(Tuple t) {
    get<0>(t) += "*";
    get<1>(t) += 100;
    get<2>(t) = get<2>(t) / 2;

    return t; // return modified copy
}

// modify Tuple 
tuple<string, double> compressTuple(const Tuple& t) {
    string summary = get<0>(t) + "-" + to_string(get<1>(t));
    double score = get<1>(t) + get<2>(t);
    return make_tuple(summary, score);
}

int main() {
    vector<string> v1{ "one", "two", "three", "four", "five", "six" };

    vector<int> v2{ 1, 2, 3, 4, 5, 6 };

    vector<double> v3{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    // initial tuple
    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
    printTupleOfThree(t0);

    // new tuple
    auto t1 = funtup(v1[1], v2[1], v3[1]);
    printTupleOfThree(t1);

    // modified tuple
    auto t2 = tweakTuple(t1);
    printTupleOfThree(t2);

    auto t2c = compressTuple(t2);
    cout << "("
        << get<0>(t2c) << ", "
        << get<1>(t2c) << ")"
        << endl;

    return 0;
}
