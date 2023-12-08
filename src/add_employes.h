#ifndef ADD_EMPLOYES_H
#define ADD_EMPLOYES_H

#include <QDialog>
#include "employer.h"
namespace Ui {
class add_employes;
}

class add_employes : public QDialog
{
    Q_OBJECT

public:
    explicit add_employes(QWidget *parent = nullptr);
    ~add_employes();

private slots:
    void on_b_ajouter_employes_clicked();

private:
    Ui::add_employes *ui;
};

#endif // ADD_EMPLOYES_H
