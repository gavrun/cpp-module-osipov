#include <iostream>
#include <string>

std::string privet(std::string name);

int main() {
    std::string name;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;

    std::string nameOut = privet(name);
    std::cout << nameOut;

    return 0;
}

std::string privet(std::string name) {
    std::string str = name + ", " + "hello!\n";

    return str;
}
