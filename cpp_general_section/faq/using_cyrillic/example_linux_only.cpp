#include <iostream>
#include <QString>
#include <QDebug>

void exampleLinuxOnly()
{
    std::string str;

    for (;;) {
        std::cout << "Это строка - пример правильного вывода в консоль" << std::endl;
        std::cout << "Напиши что-нибудь здесь: ";
        std::getline(std::cin, str);
        qDebug().noquote().nospace() << "Получил следующую строку QString (в кавычках чтоб наверняка): \""
                                     << QString::fromStdString(str) << "\"";
        std::cout << "Получил следующую строку string (в кавычках чтоб наверняка): \""
                   << str << "\"" << std::endl;
        std::cout << "Длина строки (дает неправильный ответ для linux): " << str.length() << std::endl;
        std::cout << std::endl;
    }
}
