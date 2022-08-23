#define TO_WSTD_STR(text) text.toStdWString()

#if _WIN32
# define TO_QSTR(text) QString::fromStdWString(text)
# include <windows.h>
# include <io.h>
# include <fcntl.h>
#elif __linux__
# define TO_QSTR(text) QString::fromStdWString(text)
#endif

#include <iostream>
#include <string>
#include <QString>
#include <QDebug>

void example3()
{
#if _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
#elif __linux__
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    std::wstring str;

    for(;;) {
        std::wcout << L"Это строка - пример правильного вывода в консоль" << std::endl;
        std::wcout << L"Напиши что-нибудь здесь: ";
        std::getline(std::wcin, str);
#if _WIN32
        std::wcin.ignore(1 << 15, '\n');
#endif
        qDebug().noquote().nospace() << "Эта строка вызывает ошибку (в win) \"Invalid parameter passed to C runtime function.\"";
        QString qstr = TO_QSTR(L"Получил следующую строку QString (в кавычках чтоб наверняка): \"")
                       + TO_QSTR(str) + TO_QSTR(L"\"");
        std::wcout << TO_WSTD_STR(qstr) << std::endl;
        std::wcout << L"Получил следующую строку wstring (в кавычках чтоб наверняка): \""
                   << str << L"\"" << std::endl;
        std::wcout << L"Длина строки: " << str.length() << std::endl;
        std::wcout << std::endl;
    }
}
