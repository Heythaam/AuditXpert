#ifndef MODIFY_EMPLOYES_H
#define MODIFY_EMPLOYES_H

#include <QDialog>

namespace Ui {
class modify_employes;
}

class modify_employes : public QDialog
{
    Q_OBJECT

public:
    explicit modify_employes(QWidget *parent = nullptr);
    ~modify_employes();
     Ui::modify_employes * getUi() {return ui;}

private slots:
     void on_appliquer_clients_clicked();

     void on_supprimer_clients_clicked();

private:
    Ui::modify_employes *ui;
};

#endif // MODIFY_EMPLOYES_H
