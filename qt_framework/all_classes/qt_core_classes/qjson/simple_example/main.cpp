#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJsonObject json_obj;   /// здесь создаем объект, который будет представлять json формат

    /// добавляем данные в json
    json_obj.insert("Давление, МПа", 15.);  /// добавление числа типа double
    json_obj.insert("Объем, м^3", 1);
    json_obj.insert("Количество лет", 100); /// типа int
    json_obj.insert("Есть на форме", false);/// типа bool
    json_obj.insert("Ляля", "тополя");      /// типа QString
    /// типа json
    json_obj.insert("Объект1", QJsonObject {
                                            {"число 1", 1},
                                            {"число 2", 2}
                                           });

    /// использование данных json в программе
    double p_MPa = json_obj["Давление, МПа"].toDouble();
    int V_m3 = json_obj["Объем, м^3"].toInt();

    qDebug() << QString("p * V = %1").arg(p_MPa * V_m3);

    /// создание документа по объекту json
    QJsonDocument json_doc(json_obj);

    /// конвертация json_doc в строку в удобочитаемом виде
    QString json_str = json_doc.toJson(QJsonDocument::Indented);

    QFile file("result.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    out.setCodec(codec);
    out << json_str;

    return 0;
}
