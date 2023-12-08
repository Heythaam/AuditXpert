#ifndef QR_CODE_H
#define QR_CODE_H

#include <QDialog>
#include "qrcode.h"
QT_BEGIN_NAMESPACE
using namespace qrcodegen;

namespace Ui {
class qr_code;
}

class qr_code : public QDialog
{
    Q_OBJECT

public:
    explicit qr_code(QWidget *parent = nullptr);
    ~qr_code();

private slots:
    void on_pushButton_clicked();

private:
    Ui::qr_code *ui;
};

#endif // QR_CODE_H
