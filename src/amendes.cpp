#include "amendes.h"
#include <QtDebug>
amendes::amendes()
{
 ID_amende=1;
 nom_amende="";
 montant=0;
}

amendes::amendes(int id,QString Nom,float Montant, QDate Deadline)
{
    ID_amende=id;
    nom_amende=Nom;
    montant=Montant;
    deadline=Deadline;
}

int amendes::getID()
{
    return ID_amende;
}

QString amendes::getnom()
{
    return nom_amende;
}

float amendes::getmontant()
{
    return montant;
}

QDate amendes::getdeadline()
{
    return deadline;
}
/*
void amendes::setID(int ID)
{
    this->ID_amende=ID;
}

void amendes::setnom(QString nom)
{
    this->nom_amende=nom;
}

void amendes::setmontant(int montant)
{
    this->montant=montant;
}

void amendes::setdeadline(QDate deadline)
{
    this->deadline=deadline;
}*/

bool amendes::ajouter()
{
   QSqlQuery query;
   QDate currentdate1 = currentdate1.currentDate();
   if (deadline > currentdate1){
   QString res=QString::number(ID_amende);
   QString res1=QString::number(montant);
   query.prepare("INSERT INTO AMENDES(ID_AMENDE,NOM_AMENDE,MONTANT,DEADLINE)"
                 "VALUES(:ID_AMENDE,:NOM_AMENDE, :MONTANT, :DEADLINE)");

   query.bindValue(":ID_AMENDE",res);
   query.bindValue(":NOM_AMENDE",nom_amende);
   query.bindValue(":MONTANT",res1);
   query.bindValue(":DEADLINE",deadline);
   return query.exec();
   }
   else{ return false;}
   }


bool amendes::modifier(int id )
{
QSqlQuery query;
QDate currentdate1 = currentdate1.currentDate();
if (deadline > currentdate1)
{
QString res=QString::number(id);
QString res1=QString::number(montant);
 query.prepare("UPDATE AMENDES SET NOM_AMENDE = :NOM_AMENDE, MONTANT = :MONTANT, DEADLINE = :DEADLINE WHERE ID_AMENDE = :ID_AMENDE;");

 query.bindValue(":ID_AMENDE",res);
 query.bindValue(":NOM_AMENDE",nom_amende);
 query.bindValue(":MONTANT",res1);
 query.bindValue(":DEADLINE",deadline);
return query.exec();
}
else{ return false;}
}

bool amendes::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("Delete from amendes where ID_amende= :id_amende");
query.bindValue(":id_amende",id);
return query.exec();
}



QSqlQueryModel * amendes::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_AMENDE,NOM_AMENDE,Montant,Deadline from amendes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AMENDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Deadline"));
    return model;

}

QSqlQueryModel * amendes::afficherTri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_AMENDE,NOM_AMENDE,Montant,Deadline order by MONTANT DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AMENDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Deadline"));
    return model;

}

QSqlQueryModel* amendes::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_AMENDE,NOM_AMENDE,Montant,Deadline WHERE NOM_AMENDE LIKE '%"+a+"%';");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AMENDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Deadline"));
    return model;
}

QSqlQueryModel* amendes::calendrier(QString D)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_AMENDE,NOM_AMENDE,Montant,Deadline WHERE  Deadline = TO_DATE('"+D+"', 'DD/MM/YY')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_AMENDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Deadline"));
    return model;
}
