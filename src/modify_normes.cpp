#include "modify_normes.h"
#include "ui_modify_normes.h"

modify_normes::modify_normes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_normes)
{
    ui->setupUi(this);
}

modify_normes::~modify_normes()
{
    delete ui;
}

void modify_normes::on_b_modifier_normes_clicked()
{

  QString ID=ui->le_id_u_normes->text();
    QString type=ui->le_type_u_normes->text();
    int validity=ui->le_validity_u_normes->text().toInt();
    QString sector=ui->le_sector_u_normes->text();
    QDate date=ui->le_date_u_normes->date();
    Norme N(ID,type,validity,sector,date);
    if(N.modifier(ID,type,validity,sector,date)){
        QSystemTrayIcon trayIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/notification.jpg"));
        trayIcon.setVisible(true);
        trayIcon.show();
        trayIcon.showMessage("Gestion des Normes","Normes est modifié",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("modification effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}

void modify_normes::on_b_supprimer_normes_clicked()
{
  QString ID=ui->le_id_u_normes->text();
    QString type=ui->le_type_u_normes->text();
    int validity=ui->le_validity_u_normes->text().toInt();
    QString sector=ui->le_sector_u_normes->text();
    QDate date=ui->le_date_u_normes->date();
    Norme N(ID,type,validity,sector,date);
    if(N.supprimer(ID)){
        QSystemTrayIcon trayIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/notification.jpg"));
        trayIcon.setVisible(true);
        trayIcon.show();
        trayIcon.showMessage("Gestion des Normes","Normes est supprimé",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Suppression effectué\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
        hide();
}
}
