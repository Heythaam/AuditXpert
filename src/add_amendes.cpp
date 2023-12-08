#include "add_amendes.h"
#include "ui_add_amendes.h"
#include "amendes.h"
#include <qmessagebox.h>
add_amendes::add_amendes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_amendes)
{
    ui->setupUi(this);
    ui->le_id_amendes->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_montant_amendes->setValidator(new QRegExpValidator(QRegExp("^\\d{0,8}$"), this));
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]{1,10}"), this);
    ui->le_nom_amendes->setValidator(validator);
}

add_amendes::~add_amendes()
{
    delete ui;
}

void add_amendes::on_b_ajouter_amendes_clicked()
{
    int id=ui->le_id_amendes->text().toInt();
    QString nom=ui->le_nom_amendes->text();
    float montant=ui->le_montant_amendes->text().toFloat();
    QDate deadline=ui->le_date_amendes->date();
    amendes a(id, nom,montant, deadline);
    if (a.ajouter())
        {
            QMessageBox::information(nullptr, QObject::tr("success"),
                                     QObject::tr("ajout succesfull.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            hide();
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("ajout failed\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            hide();
        }
}
