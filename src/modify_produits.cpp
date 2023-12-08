#include "modify_produits.h"
#include "ui_modify_produits.h"

modify_produits::modify_produits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_produits)
{
    ui->setupUi(this);
}

modify_produits::~modify_produits()
{
    delete ui;
}

void modify_produits::on_b_modifier_produits_clicked()
{

  int ID=ui->le_id_u_produits->text().toInt();
  QString nom=ui->le_nom_u_produits->text();
  double price=ui->le_prix_u_produits->text().toDouble();
  int quantity=ui->le_id_u_produits->text().toInt();
  Product s(ID,nom,price,quantity);
    if(s.updateProduct()){

        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
    }
}



void modify_produits::on_b_supprimer_produits_clicked()
{

  int ID=ui->le_id_u_produits->text().toInt();
  QString nom=ui->le_nom_u_produits->text();
  double price=ui->le_prix_u_produits->text().toDouble();
  int quantity=ui->le_id_u_produits->text().toInt();
  Product s(ID,nom,price,quantity);
    if(s.removeProduct(ID)){

        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
    }
}
