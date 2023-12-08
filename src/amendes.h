#ifndef AMENDES_H
#define AMENDES_H
#include <QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>


class amendes
{
public:
    amendes();
    amendes(int, QString,float,QDate);
    int getID();
    QString getnom();
    float getmontant();
    QDate getdeadline();


    /*void setID(int);
    void setnom(QString);
    void setmontant(int);
    void setdeadline(QDate);*/
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherTri();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercher(QString a);
    QSqlQueryModel * calendrier(QString D);


private:
QString  nom_amende;
int ID_amende;
QDate deadline;
float montant;



};

#endif // AMENDES_H

