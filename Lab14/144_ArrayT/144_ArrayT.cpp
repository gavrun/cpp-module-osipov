#include <iostream>
#include <cstdlib>

// array template
template <class T, class T1>
class array {
public:
    explicit array(int size);
    ~array();

    T1 sum();
    T  average_value();
    void show_array();
    int add_value(T value);

private:
    T* data{ nullptr };
    int size{ 0 };
    int index{ 0 };
};

template <class T, class T1>
array<T, T1>::array(int size) {
    data = new T[size];
    if (data == nullptr) {
        std::cerr << "Error memory ---- exit program\n";
        std::exit(1);
    }
    array::size = size;
    array::index = 0;
}

template <class T, class T1>
array<T, T1>::~array() {
    delete[] data;
}

template <class T, class T1>
T1 array<T, T1>::sum() {
    T1 s = 0;
    for (int i = 0; i < index; ++i) s += data[i];
    return s;
}

template <class T, class T1>
T array<T, T1>::average_value() {
    if (index == 0) return T{};
    T1 s = 0;
    for (int i = 0; i < index; ++i) s += data[i];
    return static_cast<T>(s / index);
}

template <class T, class T1>
void array<T, T1>::show_array() {
    for (int i = 0; i < index; ++i) std::cout << data[i] << ' ';
    std::cout << '\n';
}

template <class T, class T1>
int array<T, T1>::add_value(T value) {
    if (index == size) return -1;
    data[index++] = value;
    return 0;
}

int main() {
    // Int array 
    array<int, long> numbers(100);

    for (int i = 0; i < 50; ++i) numbers.add_value(i);
    
    numbers.show_array();
    
    std::cout << "Sum = " << numbers.sum() << '\n';
    std::cout << "Average = " << numbers.average_value() << '\n';

    // Float array 
    array<float, float> values(200);

    for (int i = 0; i < 100; ++i) values.add_value(i * 100.0f);

    values.show_array();

    std::cout << "Sum = " << values.sum() << '\n';
    std::cout << "Average = " << values.average_value() << '\n';

    return 0;
}
