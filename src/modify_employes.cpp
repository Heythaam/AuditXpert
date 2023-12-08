#include "modify_employes.h"
#include "ui_modify_employes.h"
#include "employer.h"
modify_employes::modify_employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_employes)
{
    ui->setupUi(this);
}

modify_employes::~modify_employes()
{
    delete ui;
}

void modify_employes::on_appliquer_clients_clicked()
{
    QString id=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString poste=ui->le_role->text();
    QString mail=ui->le_mail->text();
    QTime starttime=ui->time_start_add->time();
    QTime endtime=ui->time_finish_add->time();
    int age=ui->age_add_employe->text().toInt();
    QString password=ui->password_add->text();

    Employer E(id,nom,poste,mail,starttime,endtime,password,age);
    if(E.modifier(id,nom,poste,mail,starttime,endtime,password,age)){


        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}

void modify_employes::on_supprimer_clients_clicked()
{
    QString id=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString poste=ui->le_role->text();
    QString mail=ui->le_mail->text();
    QTime starttime=ui->time_start_add->time();
    QTime endtime=ui->time_finish_add->time();
    int age=ui->age_add_employe->text().toInt();
    QString password=ui->password_add->text();

    Employer E(id,nom,poste,mail,starttime,endtime,password,age);
    if(E.supprimer(id)){


        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}
