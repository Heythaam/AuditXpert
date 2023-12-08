#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QObject>
#include <QDate>
#include<QDateEdit>
#include<QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include<QTableView>



Client::Client()
{
  idclient=0;nomclient=" ";domaineclient=" ";

}
Client::Client(int idclient,QString nomclient ,QString domaineclient,QDate dateajout)
{
    this->idclient=idclient; this->domaineclient=domaineclient;this->dateajout=dateajout;
    this->nomclient=nomclient;


}
int Client::getid()
{return idclient;}
QString Client::getnom()
{return nomclient;}
QString Client::getdomaine()
{return domaineclient;}
QDate Client::getdate()
{return dateajout;}
//setters
void Client::setid(int idclient)
{this->idclient=idclient;}
void Client:: setnom(QString nomclient)
{this->nomclient=nomclient;}
void Client::setdomaine(QString domaineclient)
{this->domaineclient=domaineclient;}
void Client::setDate(QDate dateajout)
{this->dateajout=dateajout;}

bool Client::ajouter()
{
        QSqlQuery query;
        QString id_string = QString::number(idclient);
        QDate currentdate1 = currentdate1.currentDate();
          if (dateajout >= currentdate1){
        query.prepare("INSERT INTO CLIENTS (IDCLIENT, NOMCLIENT, DOMAINECLIENT, DATEAJOUT) "
                      "VALUES (:IDCLIENT, :NOMCLIENT, :DOMAINECLIENT, :DATEAJOUT)");
        query.bindValue(":IDCLIENT", id_string);
        query.bindValue(":NOMCLIENT", nomclient);
        query.bindValue(":DOMAINECLIENT", domaineclient);
        query.bindValue(":DATEAJOUT", dateajout);

        if (query.exec()) {
            // The insertion was successful
            qDebug() << "Insertion successful!";
            return true;
        } else {
            // The insertion failed, and you can output an error message for debugging
            qDebug() << "Error: " << query.lastError().text();
            return false;
        }
          }
          else{ return false;}
          }




QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
                  model->setQuery("SELECT * FROM CLIENTS");
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMCLIENT"));
                  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINECLIENT"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEAJOUT"));

 return model;
}


bool Client::modifier(QString nomclient, QString domaineclient )
{
QSqlQuery query;
QString res=QString::number(idclient);
 query.prepare("UPDATE CLIENTS SET  IDCLIENT = :IDCLIENT, NOMCLIENT=:NOMCLIENT, DOMAINECLIENT = :DOMAINECLIENT, DATEAJOUT = :DATEAJOUT WHERE IDCLIENT = :IDCLIENT");
 query.bindValue(":IDCLIENT",res);
 query.bindValue(":NOMCLIENT",nomclient);
 query.bindValue(":DOMAINECLIENT",domaineclient);
 query.bindValue(":DATEAJOUT",dateajout);
return query.exec();
}
bool Client::supprimer(int idClient )
{
    QSqlQuery query;
    QString id_string=QString::number(idClient);
    query.prepare("Delete from Clients where idClient=:idClient ");

    query.bindValue(":idClient", idClient);

    return query.exec();
}

QSqlQueryModel* Client::rechercher(const QString &recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM CLIENTS WHERE ";

    // Ajoutez des conditions pour chaque colonne que vous voulez rechercher
    //queryStr += "IDCLIENT LIKE :recherche OR ";
    queryStr += "NOMCLIENT LIKE :recherche";
    /*queryStr += "DOMAINECLIENT LIKE :recherche OR ";
    queryStr += "DATEAJOUT LIKE:recherche OR ";*/


    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":recherche", "%" + recherche + "%");

    if (query.exec())
    {
        model->setQuery(query);
    }
    else {
        qDebug() << "Erreur de recherche : " ;
    }

    return model;
}

QSqlQueryModel* Client::recherchernom(QString rech)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS WHERE NOMCLIENT LIKE '%"+rech+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("domaine"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));

    return model;
}

QSqlQueryModel * Client::trinom()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by NOMCLIENT ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("domaine"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
     return model;
}

QSqlQueryModel * Client::triID()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by IDCLIENT ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMCLIENT"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINECLIENT"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEAJOUT"));
     return model;
}

QSqlQueryModel * Client::triDomaine()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM CLIENTS order by DOMAINECLIENT ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMCLIENT"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINECLIENT"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEAJOUT"));
     return model;
}




























/*
void rechercher(QString& searchTerm, QTableView* g)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM clients WHERE NOMCLIENT LIKE :searchTerm OR IDCLIENT = :searchTerm OR DOMAINECLIENT LIKE :searchTerm");
    qry.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (qry.exec()) {
        // Clear the existing content of the table
        g->setModel(nullptr);

        // Add headers to the table
        QStringList headers;
        headers << "ID" << "Nom" << "Domaine" << "Date Ajout";
        g->setHorizontalHeaderLabels(headers);

        // Populate the table with query results
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(qry);
        g->setModel(model);

        qDebug() << "Search successful!";
    } else {
        qDebug() << "Error in search query: " << qry.lastError().text();
    }
}



void rechercher(QString& a,QTableView *g )
{
QSqlQuery qry;
   qry.prepare("SELECT * FROM clients WHERE NOMCLIENT LIKE :searchTerm OR IDCLIENT = :searchTerm OR DOMAINECLIENT LIKE :searchTerm");
   qry.bindValue(":searchTerm", "%" + searchTerm + "%");

   if (qry.exec()) {
       // Clear the existing content of the table
       table->clearContents();
       table->setRowCount(0);

       // Add headers to the table
       QStringList headers;
       headers << "ID" << "Nom" << "Domaine" << "Date Ajout";
       table->setHorizontalHeaderLabels(headers);

       // Populate the table with query results
       int row = 0;
       while (qry.next()) {
           table->insertRow(row);

           QTableWidgetItem* idItem = new QTableWidgetItem(qry.value("IDCLIENT").toString());
           QTableWidgetItem* nomItem = new QTableWidgetItem(qry.value("NOMCLIENT").toString());
           QTableWidgetItem* domaineItem = new QTableWidgetItem(qry.value("DOMAINECLIENT").toString());
           QTableWidgetItem* dateItem = new QTableWidgetItem(qry.value("DATEAJOUT").toString());

           table->setItem(row, 0, idItem);
           table->setItem(row, 1, nomItem);
           table->setItem(row, 2, domaineItem);
           table->setItem(row, 3, dateItem);

           ++row;
       }

       qDebug() << "Search successful!";
   } else {
       qDebug() << "Error in search query: " << qry.lastError().text();
   }
}

void Client::rechercher(QString a,QTableView *g )
{ QSqlQuery qry;
             QSqlQueryModel *m=new QSqlQueryModel();//initialisation
             qry.prepare("select * from clients where NOMCLIENT='"+a+"'");

             qry.exec();
                     m->setQuery(qry);
             g->setModel(m);

}
*/
