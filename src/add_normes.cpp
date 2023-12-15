#include "add_normes.h"
#include "ui_add_normes.h"
#include "normes.h"
add_normes::add_normes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_normes)
{
    ui->setupUi(this);
    QValidator* IDValidator = new QRegExpValidator(QRegExp("[0-9]+"));
    QValidator* typeValidator = new QRegExpValidator(QRegExp("[A-Za-z ]+"));
    QValidator* sectorValidator = new QRegExpValidator(QRegExp("[A-Za-z0-9@.]+"));
    QValidator* validityValidator = new QRegExpValidator(QRegExp("[0-9:]+"));
    ui->le_id_normes->setValidator(IDValidator);
    ui->le_id_normes->setMaxLength(8);
    ui->le_type_normes->setValidator(typeValidator);
    ui->le_type_normes->setMaxLength(20);
    ui->le_validity_normes->setValidator(validityValidator);
    ui->le_validity_normes->setMaxLength(20);
    ui->le_sector_normes->setValidator(sectorValidator);
    ui->le_sector_normes->setMaxLength(20);
}

add_normes::~add_normes()
{
    delete ui;
}

void add_normes::on_b_ajouter_normes_clicked()
{
    QString ID_Norme=ui->le_id_normes->text();
        QString type_Norme=ui->le_type_normes->text();
        int validity=ui->le_validity_normes->text().toInt();
        QString sector=ui->le_sector_normes->text();
        QDate dateline=ui->le_date_normes->date();
       Norme N(ID_Norme, type_Norme,validity, sector,dateline);

         bool test=N.ajouter();
         if(test)
         {
            QSystemTrayIcon trayIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/notification.jpg"));
            trayIcon.setVisible(true);
            trayIcon.show();
            trayIcon.showMessage("Gestion des Normes","Normes est ajouté",QSystemTrayIcon::Information,15000);
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("ajout effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
             hide();
         }
            else{
             notification.notification_ajoutNorme();
             QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                                      QObject::tr("ajout non effectué.\n"
                                                                   "click Cancel to exit."),QMessageBox::Cancel);
             hide();
        }
}
