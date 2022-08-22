#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "unicode2ru.h"

//#define ENCODE  // comment to decode input string

int main(int argc, char *argv[])
{
#if _WIN32
    setlocale(LC_ALL,"RUSSIAN");
#elif __linux__
    setlocale(LC_ALL,"ru_RU.UTF-8");
#endif

    Unicode2Ru unicode2ru;
    std::wstring str;

#ifdef ENCODE
    for(;;) {
        std::wcout << L"Введите строку для кодирования: ";
        std::getline(std::wcin, str);
        str = unicode2ru.EncodeToDfm(QString::fromStdWString(str)).toStdWString();
        std::wcout << str << L"\n";
    }
#else
    for(;;) {
        std::wcout << L"Введите строку для декодирования: ";
        std::getline(std::wcin, str);
        str = unicode2ru.DecodeFromDfm(QString::fromStdWString(str)).toStdWString();
        std::wcout << str << L"\n";
    }
#endif

    return 0;
}
