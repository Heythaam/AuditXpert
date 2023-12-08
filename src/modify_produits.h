#ifndef MODIFY_PRODUITS_H
#define MODIFY_PRODUITS_H

#include <QDialog>
#include "product.h"
#include <QMessageBox>
namespace Ui {
class modify_produits;
}

class modify_produits : public QDialog
{
    Q_OBJECT

public:
    explicit modify_produits(QWidget *parent = nullptr);
    ~modify_produits();
    Ui::modify_produits * getUi() {return ui;}

private slots:
    void on_b_modifier_produits_clicked();

    void on_b_supprimer_produits_clicked();

private:
    Ui::modify_produits *ui;
};

#endif // MODIFY_PRODUITS_H
