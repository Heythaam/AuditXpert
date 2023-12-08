#include "product.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QtCharts>
//#include "arduino.h"

Product::Product() {
    ID = 1;
    name = "";
    price = 0.0;
    quantity = 0;
}

Product::Product(int id, const QString& Name, double Price, int Quantity) {
    ID = id;
    name = Name;
    price = Price;
    quantity = Quantity;
}

int Product::getID() const {
    return ID;
}

QString Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setID(int id) {
    ID = id;
}

void Product::setName(const QString& Name) {
    name = Name;
}

void Product::setPrice(double Price) {
    price = Price;
}

void Product::setQuantity(int Quantity) {
    quantity = Quantity;
}

bool Product::addProduct() {
    QSqlQuery query;
    query.prepare("INSERT INTO PRODUCTS (ID, NAME, PRICE, QUANTITY) VALUES (:ID, :NAME, :PRICE, :QUANTITY)");
    query.bindValue(":ID", ID);
    query.bindValue(":NAME", name);
    query.bindValue(":PRICE", price);
    query.bindValue(":QUANTITY", quantity);
    return query.exec();
}

bool Product::removeProduct(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM PRODUCTS WHERE ID = :ID");
    query.bindValue(":ID", id);
    return query.exec();
}

bool Product::updateProduct() {
    QSqlQuery query;

    QString res = QString::number(ID);

    QStringList updates;

    if (!name.isEmpty())
        updates << "NAME=:NAME";

    if (price!=0)
        updates << "PRICE=:PRICE";

    if (quantity!=0)
        updates << "QUANTITY=:QUANTITY";


    QString update_query = "UPDATE PRODUCTS SET " + updates.join(", ") + " WHERE ID=:ID";

    query.prepare(update_query);

    query.bindValue(":ID", res);

    if (!name.isEmpty())
        query.bindValue(":NAME",name);

    if (price>=0)
        query.bindValue(":PRICE",price);

    if (quantity>=0)
        query.bindValue(":QUANTITY", quantity);

    return query.exec();
}
QSqlQueryModel* Product::displayProducts(QString sortColumn)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString query = "SELECT * FROM PRODUCTS ORDER BY " + sortColumn;
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRICE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUATITY"));
    return model;
}

void Product::displayInventoryColumnChart()
{
    // Create a QMap to store the unique names and their corresponding nombres
    QMap<QString, int> stats;

    // Get all the equipements in the inventory
    QSqlQuery query;
    query.prepare("SELECT NAME, PRICE FROM PRODUCTS");
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
    chart->setTitle("PRODUCTS STATISTICS");
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
bool Product::UpdateQrcodeLink(QString qr, QString id) {
    QSqlQuery query;
    query.prepare("UPDATE PRODUCTS SET QR_CODE= :qrc where id= :id");
    query.bindValue(":qrc", qr);
    query.bindValue(":id", id);
    return query.exec();
}

/*void Product::on_Open_clicked()
{
    A.write_to_arduino("1");

}

void Product::on_Close_clicked()
{
    A.write_to_arduino("2");

}
QSqlQueryModel* Product::afficherarduino()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT *  FROM HISTARD");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("HIST"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("OPEN"));


    return model;
}*/


QSqlQueryModel * Product::afficherTri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produits order by PRICE DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRICE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITY"));
    return model;

}
