#include <iostream>
#include <tuple>
#include <vector>

// template recursion
template <class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(const Tuple& t) {
        TuplePrinter<Tuple, N - 1>::print(t);    // print first N-1
        std::cout << ", " << std::get<N - 1>(t); // then print the N-th (index N-1)
    }
};

// first element
template <class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print(const Tuple& t) {
        std::cout << std::get<0>(t);
    }
};

// empty tuple
 template <class Tuple>
 struct TuplePrinter<Tuple, 0> {
     static void print(const Tuple&) { }
 };

// variadic template function
template <class... Args>
void printTuple(const std::tuple<Args...>& t) {
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")" << std::endl;
}

int main()
{
    std::vector<std::string> v1{ "one", "two", "three", "four", "five", "six" };
    std::vector<int>    v2{ 1, 2, 3, 4, 5, 6 };
    std::vector<float>  v3{ 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };

    auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
    auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);

    printTuple(t1);
    printTuple(t2);

    return 0;
}

