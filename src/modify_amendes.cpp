#include "modify_amendes.h"
#include "ui_modify_amendes.h"

modify_amendes::modify_amendes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_amendes)
{
    ui->setupUi(this);
    ui->le_montant_u_amendes->setValidator(new QRegExpValidator(QRegExp("[0-9.]{0,255}"),this));
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]{1,10}"), this);
    ui->le_nom_u_amendes->setValidator(validator);
}

modify_amendes::~modify_amendes()
{
    delete ui;
}

void modify_amendes::setamendes(amendes a)
{
    ui->le_id_u_amendes->setText(QString::number(a.getID()));
    ui->le_nom_u_amendes->setText(a.getnom());
    ui->le_montant_u_amendes->setText(QString::number(a.getmontant()));
    ui->le_date_u_amendes->setDate(a.getdeadline());
}

void modify_amendes::on_appliquer_amendes_clicked()
{
    int id=ui->le_id_u_amendes->text().toInt();
    QString nom=ui->le_nom_u_amendes->text();
    float montant=ui->le_montant_u_amendes->text().toFloat();
    QDate deadline=ui->le_date_u_amendes->date();
    amendes a(id,nom,montant,deadline);
    if (a.modifier(id))
    {
        QMessageBox::information(nullptr, QObject::tr("success"),
                                 QObject::tr("update succesfull.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void modify_amendes::on_supprimer_amendes_clicked()
{
    int id=ui->le_id_u_amendes->text().toInt();
    QString nom=ui->le_nom_u_amendes->text();
    float montant=ui->le_montant_u_amendes->text().toFloat();
    QDate deadline=ui->le_date_u_amendes->date();
    amendes a(id, nom,montant, deadline);
        if (a.supprimer(id))
        {
            QMessageBox::information(nullptr, QObject::tr("success"),
                                     QObject::tr("delete succesfull.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            hide();
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("delete failed\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
