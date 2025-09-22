// UTF-8 без BOM

#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // Консоль в UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // Показываем «честный» стандарт (ключ /Zc:__cplusplus включён в настройках)
#if __cplusplus >= 201103L
    std::cout << "It's C++11 or higher\n";
#else
    std::cout << "It's pre-C++11\n";
#endif

#if __cplusplus == 202002L
    std::cout << "It's C++20\n";
#elif __cplusplus == 201703L
    std::cout << "It's C++17\n";
#elif __cplusplus == 201402L
    std::cout << "It's C++14\n";
#elif __cplusplus == 201103L
    std::cout << "It's C++11\n";
#endif

    std::cout << "__cplusplus = " << __cplusplus << "\n";
#ifdef _MSC_VER
    std::cout << "_MSC_VER = " << _MSC_VER << " (MSVC toolset)\n";
#endif

    std::cout << u8"Проверка вывода на UTF-8: Привет, мир!\n";
    return 0;
}

