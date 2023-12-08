#ifndef MODIFY_AMENDES_H
#define MODIFY_AMENDES_H

#include <QDialog>
#include "amendes.h"
#include <QMessageBox>
namespace Ui {
class modify_amendes;
}

class modify_amendes : public QDialog
{
    Q_OBJECT

public:
    explicit modify_amendes(QWidget *parent = nullptr);
    ~modify_amendes();
    void setamendes(amendes a);
    Ui::modify_amendes * getUi() {return ui;}

private slots:
    void on_appliquer_amendes_clicked();

    void on_supprimer_amendes_clicked();

private:
    Ui::modify_amendes *ui;
};

#endif // MODIFY_AMENDES_H
