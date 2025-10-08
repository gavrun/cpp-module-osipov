#include <iostream>
#include <string>

void privet(std::string name);

int main() {
    std::string name;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name; 
    
    privet(name);

    return 0;
}

void privet(std::string name) {
    std::cout << name << ", " << "hello!" << std::endl;
}
