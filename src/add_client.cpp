#include "add_client.h"
#include "ui_add_client.h"
#include "client.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QAbstractItemModel>
//#include <dialogstat.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPixmap>
#include <QComboBox>

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(100, 999, this));
    x = rand() % 5 + 1;
  QString imagePath = ":/new/prefix1/res/"+QString::number(x)+".jpg";
  QPixmap pixmap(imagePath);
  ui->label_8->setPixmap(pixmap);
}

add::~add()
{
    delete ui;
}

void add::on_b_ajouter_clicked()
{
       int id=ui->le_id->text().toInt();
      QString nom=ui->le_nom->text();
      QString domaine=ui->le_domaine->text();
      QDate date=ui->le_date->date();
      QString recap=ui->captcha->text();
      Client C(id,nom,domaine,date);
      QSqlQuery qry;
      QString val=QString::number(x)+".jpg";
      QString retrievedValue;
      qry.prepare("select value from reca where id='"+val+"' " );
      qry.exec();
      if (qry.next()) {
          retrievedValue = qry.value(0).toString();
    if (retrievedValue==recap){

      if (C.ajouter())
      {
          //ui->tabclient->setModel(C.afficher());
          //ui->groupBox->setTitle("Success");
          QMessageBox::information(nullptr, QObject::tr("success"),
                                   QObject::tr("ajout succesfull.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

          QFile file("C:/Users/Heytham/Desktop/qt/integration_finale/historique.txt");
          if(!file.open(QIODevice::Append | QIODevice::Text)){

              qDebug() << "Erreur.";
          }

          QDateTime dateTime=QDateTime::currentDateTime();
          QTextStream outFile(&file);

          outFile << "Evenement : Ajout d'un client | Date : " << dateTime.toString() <<"\n";
          file.close();

      }
      else
      {
          //file:///C:/Users/LENOVO/Downloads/Atelier_Connexionf/client/res/5.jpg
          file:///C:/Users/Heytham/Desktop/qt/integration_finale/res/5.jpg
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                   QObject::tr("ajout failed\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
      }

      recap="";
      x = rand() % 5 + 1;
  QString imagePath = ":/new/prefix1/res/"+QString::number(x)+".jpg";
  QPixmap pixmap(imagePath);
    ui->label_8->setPixmap(pixmap);
      }else {
          x = rand() % 5 + 1;
  QString imagePath = ":/new/prefix1/res/"+QString::number(x)+".jpg";
  QPixmap pixmap(imagePath);
        ui->label_8->setPixmap(pixmap);
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("recapacha failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }}

    }
