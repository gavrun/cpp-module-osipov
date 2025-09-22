// UTF-8 без BOM

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    std::ios::sync_with_stdio(false);

    std::string mode = (argc >= 2) ? argv[1] : "--endl";
    bool use_endl = (mode == "--endl");

    if (use_endl) {
        std::cout << u8"[mode] --endl (с flush)\n";
        std::cout << "this is " << std::endl; // flush
    }
    else {
        std::cout << u8"[mode] --newline (без flush)\n";
        std::cout << "this is " << "\n";      // без flush
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "AAAA!!!" << std::endl; // финальный перевод строки + flush
    return 0;
}

