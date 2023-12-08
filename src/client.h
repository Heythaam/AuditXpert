#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QString>
#include <QDate>
#include<QDateEdit>
#include<QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include <QTableView>


class Client
{
public:
    //constructors
    Client();
    Client (int,QString,QString,QDate);
    //getters
    int getid();
    QString getnom();
    QString getdomaine();
    QDate getdate();
    //setters
    void setid(int);
    void setnom(QString);
    void setdomaine(QString);
    void setDate(QDate);
    //fonctionnalitées de base
    bool ajouter();
    QSqlQueryModel * afficher();
   bool supprimer(int);
    bool modifier(QString,QString);
   //les metiers
    void exportToPDF(QWidget widget);
   QSqlQueryModel* rechercher(const QString &recherche);
   QSqlQueryModel* recherchernom(QString recherche);
   QSqlQueryModel * trinom();
   QSqlQueryModel * triID();
   QSqlQueryModel * triDomaine();

private:
    int idclient;
    QString nomclient;
    QString domaineclient;
    QDate  dateajout;

};

#endif // CLIENT_H
