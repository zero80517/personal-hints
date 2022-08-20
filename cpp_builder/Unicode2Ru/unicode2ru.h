#ifndef UTF8RU_H
#define UTF8RU_H

#include <QMap>
#include <QString>

/**
 * @brief Перевести из кода UTF-8 в ру текст.
 * @see <a href="https://en.wikipedia.org/wiki/Cyrillic_script_in_Unicode#Table_of_characters">Таблица в википедии (только hex коды)</a>
 * @see <a href="https://ru.wikipedia.org/wiki/%D0%9A%D0%B8%D1%80%D0%B8%D0%BB%D0%BB%D0%B8%D1%86%D0%B0_(%D0%B1%D0%BB%D0%BE%D0%BA_%D0%AE%D0%BD%D0%B8%D0%BA%D0%BE%D0%B4%D0%B0)#%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA_%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%BE%D0%B2">
 * Таблица в википедии, где есть десятичные коды</a>
 */
class Unicode2Ru
{
public:
    Unicode2Ru();

    /**
     * @brief Декодировать текст с .dfm файла.
     * @warning Желательно посылать корректную строку. Иначе получится некорректный ответ.
     * @todo Надо бы доделать как нибудь используя регулярные выражения.
     * Надо всего-лишь выделить символы в формате #xxxx и ' '.
     */
    QString DecodeFromDfm(const QString& encoded_text);

    QMap<QString,QString> hex_code;///< отображение hex кодировки в ру символ
    QMap<QString,QString> dec_code;///< отображение dec кодировки в ру символ
};

#endif // UTF8RU_H
