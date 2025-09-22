// UTF-8 без BOM

#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cerr << u8"[diag] Программа читает целые из stdin. "
        u8"Повторы подряд будут выведены в stdout.\n";
    std::cout << u8"Введите числа (Ctrl+Z, Enter — завершить): " << std::flush;

    int prev = 0, curr = 0;
    bool have_prev = false;
    while (std::cin >> curr) {
        if (have_prev && prev == curr) {
            std::cout << u8"Повтор числа: " << curr << '\n';
        }
        have_prev = true;
        prev = curr;
    }
    std::cerr << u8"[diag] Входной поток закрыт, завершаемся.\n";
    return 0;
}

