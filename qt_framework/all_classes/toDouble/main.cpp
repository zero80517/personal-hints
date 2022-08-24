#include <QCoreApplication>
#include <iostream>
#include <QLocale>
#include <QIODevice>
#include <QTextStream>
#include <QTextCodec>
#include <QFile>
#include <Qt>
#include <QDebug>
#include "omp.h"

#define NUM_ITER 1e7

namespace PointDecimal {

    namespace NoThrow {
        namespace NoCopy {

            namespace Locale {

            double StrToDouble(const QString &str, bool* ok=nullptr) noexcept {
                static QLocale ru_locale(QLocale::Russian, QLocale::Russia);
                static QLocale en_locale(QLocale::English, QLocale::UnitedStates);

                double result = ru_locale.toDouble(str, ok);

                if (!ok) {
                    result = en_locale.toDouble(str, ok);

                    return result;
                } else {
                    return result;
                }
            }

            } // Locale

            namespace Replace {

            double StrToDouble(QString & str, bool *ok=nullptr) noexcept {
                str.replace(",", ".");

                return str.toDouble(ok);
            }

            } // Replace

        } // NoCopy
    } // NoThrow

    namespace StringView {

        namespace Locale {

        double StrToDouble(const QStringView &str) {
            static QLocale ru_locale(QLocale::Russian, QLocale::Russia);
            static QLocale en_locale(QLocale::English, QLocale::UnitedStates);

            bool ok;

            double result = ru_locale.toDouble(str, &ok);

            if (!ok) {
                result = en_locale.toDouble(str, &ok);

                if (!ok) {
                    throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());
                } else {
                    return result;
                }
            } else {
                return result;
            }
        }

        } // Locale

    } // StringView


    namespace NoCopy {

        namespace Locale {

        double StrToDouble(const QString &str) {
            static QLocale ru_locale(QLocale::Russian, QLocale::Russia);
            static QLocale en_locale(QLocale::English, QLocale::UnitedStates);

            bool ok;

            double result = ru_locale.toDouble(str, &ok);

            if (!ok) {
                result = en_locale.toDouble(str, &ok);

                if (!ok) {
                    throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());
                } else {
                    return result;
                }
            } else {
                return result;
            }
        }

        } // Locale

        namespace Replace {

        double StrToDouble(QString & str) {
            str.replace(",", ".");

            bool ok;

            double result = str.toDouble(&ok);

            if (!ok)
                throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());

            return result;
        }

        } // Replace

    } // NoCopy

} // PointDecimal

namespace Copy {

    namespace Locale {

    double StrToDouble(const QString str) {
        static QLocale locale(QLocale::Russian, QLocale::Russia);

        bool ok;

        double result = locale.toDouble(str, &ok);

        if (!ok)
            throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());

        return result;
    }

    } // Locale

    namespace Replace {

    double StrToDouble(QString str) {
        str.replace(",", ".");

        bool ok;

        double result = str.toDouble(&ok);

        if (!ok)
            throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());

        return result;
    }

    } // Replace

} // Copy

namespace NoCopy {

    namespace Locale {

    double StrToDouble(const QString &str) {
        static QLocale locale(QLocale::Russian, QLocale::Russia);

        bool ok;

        double result = locale.toDouble(str, &ok);

        if (!ok)
            throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());

        return result;
    }

    } // Locale

    namespace Replace {

    double StrToDouble(QString & str) {
        str.replace(",", ".");

        bool ok;

        double result = str.toDouble(&ok);

        if (!ok)
            throw std::invalid_argument(QString("%1 it's not a double value!").arg(str).toStdString());

        return result;
    }

    } // Replace

} // NoCopy



void MeasureTime(QTextStream &out) {
    QString str;
    double start, end;

    str = "12.15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        PointDecimal::NoThrow::NoCopy::Locale::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12.15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        PointDecimal::NoThrow::NoCopy::Replace::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12.15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        PointDecimal::NoCopy::Locale::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12.15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        PointDecimal::NoCopy::Replace::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12.15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        PointDecimal::StringView::Locale::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12,15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        Copy::Locale::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12,15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        Copy::Replace::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12,15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        NoCopy::Locale::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\t";

    str = "12,15";
    start = omp_get_wtime();
    for (int i = 0; i < NUM_ITER; i++)
        NoCopy::Replace::StrToDouble(str);
    end = omp_get_wtime();
    out << QString("%1").arg(end - start) << "\n";

    out.flush();
}

int main(int argc, char *argv[])
{
    QFile file("result.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    out.setCodec(codec);

    out << QString("PDNTNCL")   << "\t"
        << QString("PDNTNCR")   << "\t"
        << QString("PDNCL")     << "\t"
        << QString("PDNCR")     << "\t"
        << QString("PDSVL")     << "\t"
        << QString("CL")        << "\t"
        << QString("CR")        << "\t"
        << QString("NCL")       << "\t"
        << QString("NCR")       << "\n";
    out.flush();

    for (int i = 0; i < 10; i++) {
        MeasureTime(out);
        qDebug() << QString("Iteration %1 was done").arg(i);
    }
}
