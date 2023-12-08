#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if (test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("Connection succesfull.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
QMessageBox::critical(nullptr,QObject::tr("Database is not open"), QObject::tr("Connection failed\n."
                                                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
