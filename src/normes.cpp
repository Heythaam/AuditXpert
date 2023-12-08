#include "normes.h"
#include <QDate>
#include<QDateEdit>
#include<QLineEdit>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QObject>
#include <QtCharts>

Norme::Norme()
{
    ID_Norme=" ";
    type_NORME=" ";
    validity=1;
    sector=" ";

}
Norme::Norme(QString ID_Norme,QString type,int validity,QString sector,QDate date)

{
  this->ID_Norme=ID_Norme;
  this->type_NORME=type;
  this->validity=validity;
  this->sector=sector;
    this->date=date;
}



QString Norme::getID() { return ID_Norme; }
QString Norme::gettype() { return type_NORME; }
int Norme::getvalidity() { return validity; }
QString Norme::getsector() { return sector; }
QDate Norme::getdate(){return date;}

/*//setters
void Norme::setID(QString ID)
{this->ID_Norme=ID;}
void Norme::settype(QString type_Norme)
{this->validity=validity;}
void Norme::setsector(QString sector)
{this->sector=sector;}
void Norme::setDate(QDate date)
{this->date=date;}*/



bool Norme::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(validity);

  query.prepare("INSERT INTO NORMES (ID_NORME,TYPE_NORME,VALIDITY,SECTOR ,DATELINE) VALUES(:ID_NORME,:TYPE_NORME,:VALIDITY,:SECTOR,:DATELINE)");

  query.bindValue(":ID_NORME",ID_Norme);
  query.bindValue(":TYPE_NORME",type_NORME);
  query.bindValue(":VALIDITY",res);
  query.bindValue(":SECTOR",sector);
  query.bindValue(":DATELINE",date);

  return query.exec();

 }

bool Norme::modifier(QString,QString,int,QString,QDate)
{
QSqlQuery query;

 query.prepare("UPDATE NORMES SET  TYPE_Norme =:TYPE_NORME, VALIDITY =:VALIDITY, SECTOR =:SECTOR, DATELINE =:DATELINE WHERE ID_NORME =:ID_NORME;");

 query.bindValue(":ID_NORME",ID_Norme);
 query.bindValue(":TYPE_NORME",type_NORME);
 query.bindValue(":VALIDITY",validity);
 query.bindValue(":SECTOR",sector);
 query.bindValue(":DATELINE",date);

return query.exec();
}

bool Norme::supprimer(QString ID_NORME)
{
QSqlQuery query;
query.prepare("Delete from NORMES where ID_NORME=:ID_NORME");
query.bindValue(":ID_NORME",ID_NORME);
return query.exec();
}
QSqlQueryModel *Norme::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from NORMES");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Norme"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type_Norme"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Validity"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sector"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

   return model;
}
QSqlQueryModel* Norme::rechercher(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM NORMES WHERE ID_NORME LIKE '%"+N+"%';");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Norme"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type_Norme"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("validity"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("sector"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateline"));
    return model;
}


QSqlQueryModel * Norme::triID()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM NORMES order by ID_NORME ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Norme"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_Norme"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("validity"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("sector"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
  return model;
}


QSqlQueryModel * Norme::tritype()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM NORMES order by TYPENORME ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Norme"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_Norme"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("validity"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("sector"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
     return model;
}
QSqlQueryModel * Norme::trivalidity()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM NORMES order by SECTORNORME ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Norme"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_Norme"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("validity"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("sector"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
     return model;
}
QSqlQueryModel * Norme::trisector()
{
  QSqlQueryModel* model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM NORMES order by VALIDITYNORME ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Norme"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_Norme"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("validity"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("sector"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
     return model;
}
void Norme::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
/*void   Norme::displayInventoryColumnChart()
 {
     // Create a QMap to store the unique names and their corresponding nombres
     QMap<QString, int> stats;

     // Get all the equipements in the inventory
     QSqlQuery query;
     query.prepare("SELECT SECTOR, VALIDITY FROM NORME");
     query.exec();

     // Iterate through the results and add up the nombres for each unique name
     while(query.next()) {
         QString nom = query.value(0).toString();
         int nombre = query.value(1).toInt();
         if(stats.contains(nom)) {
             if (stats[nom] != nombre) {
                 // If the name already exists in the map and the nombre is different, divide the nombre by 2
                 nombre = nombre / 2;
             } else {
                 // If the name already exists in the map and the nombre is the same, skip it
                 continue;
             }
         }
         stats[nom] = nombre;
     }

     // Create the column chart series and add the data from the QMap
     QBarSeries *series = new QBarSeries();
     QMapIterator<QString, int> i(stats);
     while (i.hasNext()) {
         i.next();
         QBarSet *set = new QBarSet(i.key());
         *set << i.value();
         series->append(set);
     }

     // Create the chart and chart view, and display the chart view
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("NORME STATISTICS");
     chart->setAnimationOptions(QChart::AllAnimations);
     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);
     QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(stats.keys());
     chart->createDefaultAxes();
     chart->setAxisX(axis, series);
     chart->setAxisY(new QValueAxis, series);
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->resize(800, 400);
     chartView->show();
 }
*/










