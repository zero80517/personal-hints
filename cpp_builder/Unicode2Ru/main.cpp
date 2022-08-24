#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "unicode2ru.h"

//#define ENCODE  // comment to decode input string

#if _WIN32
# define Char2StdStr(text) QString(text).toLocal8Bit().toStdString()
# define StdStr2QStr(text) QString::fromLocal8Bit(text.c_str(), text.size())
# define QStr2StdStr(text) text.toLocal8Bit().toStdString()
# include <windows.h>
#elif __linux__
# define Char2StdStr(text) std::string(text)
# define StdStr2QStr(text) QString::fromStdString(text)
# define QStr2StdStr(text) text.toStdString()
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
        std::cout << Char2StdStr("Введите строку для кодирования: ");
        std::getline(std::cin, str);
        str = QStr2StdStr(unicode2ru.EncodeToDfm(StdStr2QStr(str)));
        std::cout << str << std::endl << std::endl;
    }
#else
    for(;;) {
        std::cout << Char2StdStr("Введите строку для декодирования: ");
        std::getline(std::cin, str);
        str = QStr2StdStr(unicode2ru.DecodeFromDfm(StdStr2QStr(str)));
        std::cout << str << std::endl << std::endl;
    }
#endif

    return 0;
}
