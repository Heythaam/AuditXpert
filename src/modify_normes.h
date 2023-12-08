#ifndef MODIFY_NORMES_H
#define MODIFY_NORMES_H

#include <QDialog>
#include "normes.h"
#include <QMessageBox>
#include "notifications.h"
namespace Ui {
class modify_normes;
}

class modify_normes : public QDialog
{
    Q_OBJECT

public:
    explicit modify_normes(QWidget *parent = nullptr);
    ~modify_normes();
    Ui::modify_normes * getUi() {return ui;}

private slots:
    void on_b_modifier_normes_clicked();

    void on_b_supprimer_normes_clicked();

private:
    Ui::modify_normes *ui;
    notification notification;
};

#endif // MODIFY_NORMES_H
