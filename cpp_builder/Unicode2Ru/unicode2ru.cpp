#include "unicode2ru.h"

Unicode2Ru::Unicode2Ru()
{
    hex_code["0410"] = "А"; hex_code["0430"] = "а"; dec_code["1040"] = "А"; dec_code["1072"] = "а";
    hex_code["0411"] = "Б"; hex_code["0431"] = "б"; dec_code["1041"] = "Б"; dec_code["1073"] = "б";
    hex_code["0412"] = "В"; hex_code["0432"] = "в"; dec_code["1042"] = "В"; dec_code["1074"] = "в";
    hex_code["0413"] = "Г"; hex_code["0433"] = "г"; dec_code["1043"] = "Г"; dec_code["1075"] = "г";
    hex_code["0414"] = "Д"; hex_code["0434"] = "д"; dec_code["1044"] = "Д"; dec_code["1076"] = "д";
    hex_code["0415"] = "Е"; hex_code["0435"] = "е"; dec_code["1045"] = "Е"; dec_code["1077"] = "е";
    hex_code["0416"] = "Ж"; hex_code["0436"] = "ж"; dec_code["1046"] = "Ж"; dec_code["1078"] = "ж";
    hex_code["0417"] = "З"; hex_code["0437"] = "з"; dec_code["1047"] = "З"; dec_code["1079"] = "з";
    hex_code["0418"] = "И"; hex_code["0438"] = "и"; dec_code["1048"] = "И"; dec_code["1080"] = "и";
    hex_code["0419"] = "Й"; hex_code["0439"] = "й"; dec_code["1049"] = "Й"; dec_code["1081"] = "й";
    hex_code["041A"] = "К"; hex_code["043A"] = "к"; dec_code["1050"] = "К"; dec_code["1082"] = "к";
    hex_code["041B"] = "Л"; hex_code["043B"] = "л"; dec_code["1051"] = "Л"; dec_code["1083"] = "л";
    hex_code["041C"] = "М"; hex_code["043C"] = "м"; dec_code["1052"] = "М"; dec_code["1084"] = "м";
    hex_code["041D"] = "Н"; hex_code["043D"] = "н"; dec_code["1053"] = "Н"; dec_code["1085"] = "н";
    hex_code["041E"] = "О"; hex_code["043E"] = "о"; dec_code["1054"] = "О"; dec_code["1086"] = "о";
    hex_code["041F"] = "П"; hex_code["043F"] = "п"; dec_code["1055"] = "П"; dec_code["1087"] = "п";
    hex_code["0420"] = "Р"; hex_code["0440"] = "р"; dec_code["1056"] = "Р"; dec_code["1088"] = "р";
    hex_code["0421"] = "С"; hex_code["0441"] = "с"; dec_code["1057"] = "С"; dec_code["1089"] = "с";
    hex_code["0422"] = "Т"; hex_code["0442"] = "т"; dec_code["1058"] = "Т"; dec_code["1090"] = "т";
    hex_code["0423"] = "У"; hex_code["0443"] = "у"; dec_code["1059"] = "У"; dec_code["1091"] = "у";
    hex_code["0424"] = "Ф"; hex_code["0444"] = "ф"; dec_code["1060"] = "Ф"; dec_code["1092"] = "ф";
    hex_code["0425"] = "Х"; hex_code["0445"] = "х"; dec_code["1061"] = "Х"; dec_code["1093"] = "х";
    hex_code["0426"] = "Ц"; hex_code["0446"] = "ц"; dec_code["1062"] = "Ц"; dec_code["1094"] = "ц";
    hex_code["0427"] = "Ч"; hex_code["0447"] = "ч"; dec_code["1063"] = "Ч"; dec_code["1095"] = "ч";
    hex_code["0428"] = "Ш"; hex_code["0448"] = "ш"; dec_code["1064"] = "Ш"; dec_code["1096"] = "ш";
    hex_code["0429"] = "Щ"; hex_code["0449"] = "щ"; dec_code["1065"] = "Щ"; dec_code["1097"] = "щ";
    hex_code["042A"] = "Ъ"; hex_code["044A"] = "ъ"; dec_code["1066"] = "Ъ"; dec_code["1098"] = "ъ";
    hex_code["042B"] = "Ы"; hex_code["044B"] = "ы"; dec_code["1067"] = "Ы"; dec_code["1099"] = "ы";
    hex_code["042C"] = "Ь"; hex_code["044C"] = "ь"; dec_code["1068"] = "Ь"; dec_code["1100"] = "ь";
    hex_code["042D"] = "Э"; hex_code["044D"] = "э"; dec_code["1069"] = "Э"; dec_code["1101"] = "э";
    hex_code["042E"] = "Ю"; hex_code["044E"] = "ю"; dec_code["1070"] = "Ю"; dec_code["1102"] = "ю";
    hex_code["042F"] = "Я"; hex_code["044F"] = "я"; dec_code["1071"] = "Я"; dec_code["1103"] = "я";
}

QString Unicode2Ru::DecodeFromDfm(const QString& encoded_text)
{
    QString decoded_text; decoded_text.reserve(encoded_text.size() / 5);// #xxxx = 5 encoded symbols per decoded symbol

    QRegExp rx("(#\\d{4}|' ')");
    int pos = 0;

    while ((pos = rx.indexIn(encoded_text, pos)) != -1) {
        QString match = rx.cap(1).replace("#", "");

        if (match == "' '")
            decoded_text += ' ';
        else
            decoded_text += dec_code[match];
        pos += rx.matchedLength();
    }

    return decoded_text;
}

QString Unicode2Ru::EncodeToDfm(const QString& text)
{
    QString encoded_text; encoded_text.reserve(encoded_text.size() * 5);// #xxxx = 5 encoded symbols per decoded symbol

    for (auto s : text) {
        if (s == ' ') {
            encoded_text += "' '";
            continue;
        }
        if (dec_code.key(s, "") != "")
            encoded_text += "#" + dec_code.key(s);
    }

    return encoded_text;
}
