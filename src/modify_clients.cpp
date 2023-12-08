#include "modify_clients.h"
#include "ui_modify_clients.h"

modify_clients::modify_clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_clients)
{
    ui->setupUi(this);
}

modify_clients::~modify_clients()
{
    delete ui;
}

void modify_clients::on_appliquer_clients_clicked()
{
   int ID=ui->le_id_u_clients->text().toInt();
   QString nom=ui->le_nom_u_clients->text();
    QString domaine=ui->le_domaine_u_clients->text();
    QDate date=ui->le_date_u_clients->date();
    Client N(ID,nom,domaine,date);
    if(N.modifier(nom,domaine)){


        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}

void modify_clients::on_supprimer_clients_clicked()
{
   int ID=ui->le_id_u_clients->text().toInt();
   QString nom=ui->le_nom_u_clients->text();
    QString domaine=ui->le_domaine_u_clients->text();
    QDate date=ui->le_date_u_clients->date();
    Client N(ID,nom,domaine,date);
    if(N.supprimer(ID)){


        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Suppression effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}
