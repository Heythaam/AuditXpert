#ifndef NORME_H
#define NORME_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableView>
#include <QDate>

class Norme
{
public:
    Norme();
    Norme(QString ,QString  ,int ,QString ,QDate );
    QString getID();
    QString gettype();
    int getvalidity();
    QString getsector();
    QDate getdate();

    void setID(QString);
    void settype(QString);
    void setvalidity(int);
    void setsector(QString);
   void setDate(QDate);

    bool ajouter();
    bool modifier(QString,QString,int,QString,QDate);
    bool supprimer(QString ID);


QSqlQueryModel* afficher();
void clearTable(QTableView * table);


//les metier
QSqlQueryModel * triID();
QSqlQueryModel * tritype();
QSqlQueryModel * trivalidity();
QSqlQueryModel * trisector();
QSqlQueryModel * rechercher(QString N);
void displayInventoryColumnChart();
private:
QString ID_Norme;
QString type_NORME;
int validity;
QString sector;
QDate  date;
};
#endif // NORME_H
