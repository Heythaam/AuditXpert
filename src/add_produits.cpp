#include "add_produits.h"
#include "ui_add_produits.h"
#include "product.h"
add_produits::add_produits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_produits)
{
    ui->setupUi(this);
    ui->le_id_produits->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_prix_produits->setValidator(new QIntValidator(0,999999999,this));
}

add_produits::~add_produits()
{
    delete ui;
}

void add_produits::on_b_ajouter_produits_clicked()
{

    if (ui->le_id_produits->text().isEmpty() || ui->le_nom_produits->text().isEmpty() ||
        ui->le_prix_produits->text().isEmpty() || ui->le_quantity_produits->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    int id = ui->le_id_produits->text().toInt();
    QString name = ui->le_nom_produits->text();
    double price = ui->le_prix_produits->text().toDouble();
    int quantity = ui->le_quantity_produits->text().toInt();


    if (id <= 0 || price <= 0.0 || quantity < 0) {
        QMessageBox::critical(this, "Erreur", "Données invalides. Vérifiez les champs.");
        hide();
        return;
    }

    Product product(id, name, price, quantity);

    if (product.addProduct()) {
        QMessageBox::information(this, "Succès", "Produit ajouté avec succès.");
        hide();

    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter le produit.");
    }
}
