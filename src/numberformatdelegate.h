#ifndef NUMBERFORMATDELEGATE_H
#define NUMBERFORMATDELEGATE_H
#include <QStyledItemDelegate>

class NumberFormatDelegate : public QStyledItemDelegate {
public:
    NumberFormatDelegate(int precision, QObject *parent = nullptr) : QStyledItemDelegate(parent), m_precision(precision) {}

    QString displayText(const QVariant &value, const QLocale &locale) const override {
        QString formattedNum = locale.toString(value.toDouble(), 'f', m_precision);
        return formattedNum;
    }

private:
    int m_precision;
};
#endif // NUMBERFORMATDELEGATE_H
