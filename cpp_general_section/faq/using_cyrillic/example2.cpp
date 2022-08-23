#if _WIN32
#define TO_STD_STR(text) QString(text).toLocal8Bit().toStdString()
#define TO_QSTR(text) QString::fromLocal8Bit(text.c_str(), text.size())
#include <windows.h>
#elif __linux__
#define TO_STD_STR(text) std::string(text)
#define TO_QSTR(text) QString::fromStdString(text)
#endif

#include <iostream>
#include <string>
#include <QString>
#include <QDebug>

void example2()
{

#if _WIN32
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251. Нужно только будет изменить шрифт консоли на Lucida Console или Consolas
#endif

    std::string str;

    for(;;) {
        std::cout << TO_STD_STR("Это строка - пример правильного вывода в консоль") << std::endl;
        std::cout << "Это строка - пример неправильного вывода в консоль (для win), "
                     "потому что исходники чаще всего в кодировке UTF-8. "
                     "Если бы исходники были в кодировке 1251, то все было бы нормально."
                  << std::endl;
        std::cout << TO_STD_STR("Напиши что-нибудь здесь: ");
        std::getline(std::cin, str);
        qDebug().noquote().nospace() << "Получил следующую строку QString (в кавычках чтоб наверняка): \""
                                     << TO_QSTR(str) << "\"";
        std::cout << TO_STD_STR("Получил следующую строку string (в кавычках чтоб наверняка): \"")
                  << str << "\"" << std::endl;
        std::cout << TO_STD_STR("Длина строки (дает неправильный ответ для linux): ") << str.length() << std::endl;
        std::cout << std::endl;
    }
}
