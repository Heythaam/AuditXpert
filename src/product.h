#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <arduino.h>
#include <QtSerialPort/QSerialPort>

class Product
{
public:
    Product();
    Product(int id, const QString& name, double price, int quantity);

    int getID() const;
    QString getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setID(int id);
    void setName(const QString& name);
    void setPrice(double price);
    void setQuantity(int quantity);

    bool addProduct();
    //QSqlQueryModel* displayProducts();
    QSqlQueryModel* displayProducts(QString);
    bool removeProduct(int id);
    bool updateProduct();
    void displayInventoryColumnChart();
    bool UpdateQrcodeLink(QString qr, QString id);
    void on_PDF_produits_2_clicked();
    void on_stats_produits_2_clicked();
    QSqlQueryModel* afficherarduino();
    QSqlQueryModel * afficherTri();
private:
    int ID;
    QString name;
    double price;
    int quantity;
    Arduino A;

};

#endif // PRODUCT_H
