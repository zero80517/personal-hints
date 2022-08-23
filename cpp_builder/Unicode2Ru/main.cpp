#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "unicode2ru.h"

//#define ENCODE  // comment to decode input string

#if _WIN32
#define TO_STD_STR(text) QString(text).toLocal8Bit().toStdString()
#define TO_QSTR(text) QString::fromLocal8Bit(text.c_str(), text.size())
#include <windows.h>
#elif __linux__
#define TO_STD_STR(text) std::string(text)
#define TO_QSTR(text) QString::fromStdString(text)
#endif

int main(int argc, char *argv[])
{
#if _WIN32
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251. Нужно только будет изменить шрифт консоли на Lucida Console или Consolas
#endif

    Unicode2Ru unicode2ru;
    std::string str;

#ifdef ENCODE
    for(;;) {
        std::cout << TO_STD_STR("Введите строку для кодирования: ");
        std::getline(std::cin, str);
        str = unicode2ru.EncodeToDfm(TO_QSTR(str)).toStdString();
        std::cout << str << std::endl << std::endl;
    }
#else
    for(;;) {
        std::cout << TO_STD_STR("Введите строку для декодирования: ");
        std::getline(std::cin, str);
        str = unicode2ru.DecodeFromDfm(TO_QSTR(str)).toStdString();
        std::cout << str << std::endl << std::endl;
    }
#endif

    return 0;
}
