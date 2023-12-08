#ifndef ADD_PRODUITS_H
#define ADD_PRODUITS_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class add_produits;
}

class add_produits : public QDialog
{
    Q_OBJECT

public:
    explicit add_produits(QWidget *parent = nullptr);
    ~add_produits();

private slots:
    void on_b_ajouter_produits_clicked();

private:
    Ui::add_produits *ui;
};

#endif // ADD_PRODUITS_H
