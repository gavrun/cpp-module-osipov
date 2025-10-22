#include <iostream>
#include <string>

// Base class
class Item {
private:
    std::string title;
    double price{};

public:
    virtual void getdata() {
        std::cout << "\nEnter title: ";
        std::cin >> title;
        std::cout << "Enter price: ";
        std::cin >> price;
    }
    virtual void putdata() {
        std::cout << "\nTitle: " << title;
        std::cout << "\nPrice: " << price;
    }
};

// Derived class: paper book
class Paperbook : public Item {
private:
    int pages{};

public:
    void getdata() override {
        Item::getdata();
        std::cout << "Enter page count: ";
        std::cin >> pages;
    }
    void putdata() override {
        Item::putdata();
        std::cout << "\nPages: " << pages;
    }
};

// Derived class: audio book
class AudioBook : public Item {
private:
    double time{}; // minutes

public:
    void getdata() override {
        Item::getdata();
        std::cout << "Enter duration (minutes): ";
        std::cin >> time;
    }
    void putdata() override {
        Item::putdata();
        std::cout << "\nDuration: " << time;
    }
};


int main()
{
    std::cout << "Hello!\n";
    Item* pubarr[100];
    int n = 0;
    char choice;

    // Input loop
    do {
        std::cout << "\nEnter data for book or audio file (b/a)? ";
        std::cin >> choice;

        if (choice == 'b' || choice == 'B')
            pubarr[n] = new Paperbook;
        else
            pubarr[n] = new AudioBook;

        pubarr[n++]->getdata();

        std::cout << "Continue (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Output loop 
    std::cout << "\n\nGood bye!\n";
    for (int j = 0; j < n; ++j) {
        pubarr[j]->putdata();
        std::cout << "\n";
    }

    // Manual cleanup
    /*for (int j = 0; j < n; ++j) {
        delete pubarr[j];
    }
    std::cout << std::endl;*/

    return 0;
}
