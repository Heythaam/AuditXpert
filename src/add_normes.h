#ifndef ADD_NORMES_H
#define ADD_NORMES_H

#include <QDialog>
#include <QMessageBox>
#include "notifications.h"
namespace Ui {
class add_normes;
}

class add_normes : public QDialog
{
    Q_OBJECT

public:
    explicit add_normes(QWidget *parent = nullptr);
    ~add_normes();

private slots:
    void on_b_ajouter_normes_clicked();

private:
    Ui::add_normes *ui;
    notification notification;
};

#endif // ADD_NORMES_H
