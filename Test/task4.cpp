#include <iostream>

class Stack {
public:
    int _array[10];
    int _length;

    void reset() {
        _length = 0;
        for (int i = 0; i < 10; ++i) _array[i] = 0;
    }

    bool push(int value) {
        if (_length >= 10) return false;
        _array[_length] = value;
        _length++;
        return true;
    }

    void pop() {
        if (_length <= 0) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        _length--;
    }

    void print() {
        std::cout << "(";
        for (int i = 0; i < _length; ++i) {
            std::cout << " " << _array[i];
        }
        std::cout << " )" << std::endl;
    }
};


int main()
{
    std::cout<<"Hello World\n";
    Stack stack;
    stack.reset();
    stack.print();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}