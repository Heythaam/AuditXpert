#ifndef EMPLOYER_H
#define EMPLOYER_H

#include<QString>
#include<QTime>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

class Employer
{
public:
    Employer();
    Employer(QString,QString,QString,QString,QTime,QTime,QString,int);
    QString getID();
    QString getNom();
    QString getPoste();
    QString getMail();
    QString getPassword();
    QTime getSTARTTime();
    QTime getENDTime();
    int getAge();
    void setID(QString);
    void setNom(QString);
    void setPoste(QString);
    void setMail(QString);
    void setSTARTTime(QTime);
    void setENDTime(QTime);
    void setPassword(QString);
    void setAge(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherTriRole();
    QSqlQueryModel * afficherTriName();
    QSqlQueryModel * afficherTriID();
    bool modifier(QString,QString,QString,QString,QTime,QTime,QString, int);
    bool supprimer(QString);
    QSqlQueryModel * rechercher(QString);
    bool search(QString,QString,QString&);
    bool getPasswordByEmail(QString, QString&);
private:
    int age;
    QString id,nom,poste,mail,password;
    QTime starttime,endtime;

};

#endif // EMPLOYER_H
