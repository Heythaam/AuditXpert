#ifndef MAIL_AMENDES_H
#define MAIL_AMENDES_H

#include <QDialog>

namespace Ui {
class mail_amendes;
}

class mail_amendes : public QDialog
{
    Q_OBJECT

public:
    explicit mail_amendes(QWidget *parent = nullptr);
    ~mail_amendes();

private slots:
    void on_SEND_clicked();

private:
    Ui::mail_amendes *ui;
};

#endif // MAIL_AMENDES_H
