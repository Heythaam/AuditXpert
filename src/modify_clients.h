#ifndef MODIFY_CLIENTS_H
#define MODIFY_CLIENTS_H
#include "client.h"
#include <QDialog>
#include <QMessageBox>
namespace Ui {
class modify_clients;
}

class modify_clients : public QDialog
{
    Q_OBJECT

public:
    explicit modify_clients(QWidget *parent = nullptr);
    ~modify_clients();
    Ui::modify_clients * getUi() {return ui;}

private slots:
    void on_appliquer_clients_clicked();

    void on_supprimer_clients_clicked();

private:
    Ui::modify_clients *ui;
};

#endif // MODIFY_CLIENTS_H
