#include "qr_code.h"
#include "ui_qr_code.h"
#include "qrcode.h"
#include "product.h"
#include <QMessageBox>
#include <qbuffer.h>
#include <qsavefile.h>
qr_code::qr_code(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qr_code)
{
    ui->setupUi(this);
}

qr_code::~qr_code()
{
    delete ui;
}

void qr_code::on_pushButton_clicked()   {

    ui->pushButton->hide();
    QSqlQuery qry;
                   qry.prepare("select * from PRODUCTS WHERE ID=:ID");
                   qry.bindValue(":ID",ui->lineEdit_6->text().toInt());
                   qry.exec();
                      QString  ID,name,price,quantity,id;

                   while(qry.next()){

                       id=qry.value(0).toString();
                       name=qry.value(1).toString();
                       price=qry.value(2).toString();
                       quantity=qry.value(3).toString();


                   }

                   ID=QString(ID);
                          ID="ID:"+id+" NAME:"+name+" PRICE:"+price+" QUANTITY:"+quantity;
                   QrCode qr = QrCode::encodeText(ID.toUtf8().constData(), QrCode::Ecc::HIGH);

                   // Read the black & white pixels
                   QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                   for (int y = 0; y < qr.getSize(); y++) {
                       for (int x = 0; x < qr.getSize(); x++) {
                           int color = qr.getModule(x, y);  // 0 for white, 1 for black

                           // You need to modify this part
                           if(color==0)
                               im.setPixel(x, y,qRgb(254, 254, 254));
                           else
                               im.setPixel(x, y,qRgb(0, 0, 0));
                       }
                   }
                   im=im.scaled(150,150);
                   ui->qrg->setPixmap(QPixmap::fromImage(im));
                   //QString path = idpr+".jpeg";
                        //QString imagePath(QStringLiteral("path/image.jpeg"));
                           QByteArray ba;
                           QBuffer buffer(&ba);
                           buffer.open(QIODevice::WriteOnly);
                           im.save(&buffer, "PNG"); // writes image into ba in PNG format
                           QSaveFile file("C:/Users/Adem/Desktop/product managment/product/code qr"+id+".png");
                           file.open(QIODevice::WriteOnly);
                           file.write(ba);
                           // Calling commit() is mandatory, otherwise nothing will be written.
                           file.commit();
                           // Now save the directory into a QString and then into the database
                           QString directory = "C:/Users/Adem/Desktop/product managment/product/code qr"+id+".png";
                           Product productModel;
                           bool qrqr = productModel.UpdateQrcodeLink(directory, id);
                           if (qrqr) {
                               QMessageBox::information(nullptr, QObject::tr("Qr code link succesfully added to the database"),
                                                        QObject::tr("Qr code effectué\n"
                                                                    "Click cancel to exit."), QMessageBox::Cancel);
                              /* ui->tableView_2->setModel(productModel.displayProducts(sortColumn));*/
                           } else
                           {
                               QMessageBox::information(nullptr, QObject::tr("Qr code link succesfully added to the database"),
                                                        QObject::tr("Qr code effectué\n"
                                                                    "Click cancel to exit."), QMessageBox::Cancel);
                           }
    }
