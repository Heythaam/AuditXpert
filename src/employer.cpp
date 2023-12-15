#include "employer.h"

Employer::Employer()
{
   nom=" ";poste=" ";mail=" ";age=0;
}


Employer::Employer(QString id,QString nom,QString poste,QString mail,QTime starttime,QTime endtime,QString password,int age)
{
    this->id=id;this->nom=nom;this->poste=poste;this->mail=mail;this->starttime=starttime;this->endtime=endtime;this->password=password;this->age=age;
}


QString Employer::getID(){return id;}
QString Employer::getNom(){return nom;}
QString Employer::getPoste(){return poste;}
QString Employer::getMail(){return mail;}
QString Employer::getPassword(){return password;}
QTime Employer::getSTARTTime(){return starttime;}
QTime Employer::getENDTime(){return endtime;}
int Employer::getAge(){return age;}
void Employer::setID(QString id){this->id=id;}
void Employer::setNom(QString nom){this->nom=nom;}
void Employer::setPoste(QString poste){this->poste=poste;}
void Employer::setMail(QString mail){this->mail=mail;}
void Employer::setSTARTTime(QTime starttime){this->starttime=starttime;}
void Employer::setENDTime(QTime endtime){this->endtime=endtime;}
void Employer::setPassword(QString password){this->password=password;}
void Employer::setAge(int age){this->age=age;}

bool Employer::ajouter()
{
   QSqlQuery query;
   query.prepare("INSERT INTO EMPLOYES(ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,PASSWORD,AGE)"
                 "VALUES(:ID_EMPLOYE,:NOM_EMPLOYE,:POSTE,:EMAIL,:START_TIME,:END_TIME,:PASSWORD,:AGE)");

   query.bindValue(":ID_EMPLOYE",id);
   query.bindValue(":NOM_EMPLOYE",nom);
   query.bindValue(":POSTE",poste);
   query.bindValue(":EMAIL",mail);
   query.bindValue(":START_TIME",starttime);
   query.bindValue(":END_TIME",endtime);
   query.bindValue(":PASSWORD",password);
   query.bindValue(":AGE",age);

    return query.exec();
}


QSqlQueryModel * Employer::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,AGE from EMPLOYES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Complet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-Mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Début"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Age"));
    return model;

}

QSqlQueryModel * Employer::afficherTriRole()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,AGE from EMPLOYES order by POSTE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Complet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-Mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Début"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Age"));
    return model;

}
QSqlQueryModel * Employer::afficherTriID()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,AGE from EMPLOYES order by ID_EMPLOYE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Complet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-Mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Début"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Age"));
    return model;

}
QSqlQueryModel * Employer::afficherTriName()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,AGE from EMPLOYES order by NOM_EMPLOYE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Complet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-Mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Début"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Age"));
    return model;

}

bool Employer::modifier(QString id,QString nom,QString poste,QString mail,QTime starttime,QTime endtime, QString password, int age)
{
QSqlQuery query;
 query.prepare("UPDATE EMPLOYES SET NOM_EMPLOYE = :NOM_EMPLOYE, POSTE = :POSTE, EMAIL = :EMAIL, START_TIME = :START_TIME, END_TIME = :END_TIME, PASSWORD = :password, AGE = :AGE WHERE ID_EMPLOYE = :ID_EMPLOYE;");
 QString res=QString::number(age);
 query.bindValue(":ID_EMPLOYE",id);
 query.bindValue(":NOM_EMPLOYE",nom);
 query.bindValue(":POSTE",poste);
 query.bindValue(":EMAIL",mail);
 query.bindValue(":START_TIME",starttime);
 query.bindValue(":END_TIME",endtime);
 query.bindValue(":PASSWORD",password);
 query.bindValue(":AGE", res);
return query.exec();
}

bool Employer::supprimer(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM EMPLOYES WHERE ID_EMPLOYE = :ID_EMPLOYE");
query.bindValue(":ID_EMPLOYE",id);
return query.exec();
}

QSqlQueryModel* Employer::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_EMPLOYE,NOM_EMPLOYE,POSTE,EMAIL,START_TIME,END_TIME,AGE from EMPLOYES where NOM_EMPLOYE LIKE '%"+a+"%'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Complet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-Mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Début"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Fin"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Age"));
    return model;
}

bool Employer::search(QString log, QString pass,  QString& poste) {
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE ID_EMPLOYE = :login AND PASSWORD = :password");
    query.bindValue(":login", log);
    query.bindValue(":password", pass);

    if (query.exec() && query.next()) {
        poste = query.value("poste").toString();
        return true;
    }
    else {
        return false;
    }
}


bool Employer::getPasswordByEmail(QString email, QString& password) {
    QSqlQuery query;
    query.prepare("SELECT PASSWORD FROM EMPLOYES WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        password = query.value("PASSWORD").toString();
        return true;
    } else {
        return false;
    }
}
