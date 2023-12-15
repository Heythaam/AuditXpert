#ifndef ARDUINO1_H
#define ARDUINO1_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class arduino1
{
public:     //méthodes de la classe arduino1
    arduino1();
    int connect_arduino1(); // permet de connecter le PC à arduino1
    int close_arduino1(); // permet de femer la connexion
    int write_to_arduino1( QByteArray ); // envoyer des données vers arduino1
    QByteArray read_from_arduino1();
    QByteArray readL_from_arduino1();//recevoir des données de la carte arduino1
    QSerialPort* getserial();   // accesseur
    QString getarduino1_port_name();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour arduino1.
    static const quint16 arduino1_uno_vendor_id=9025;
    static const quint16 arduino1_uno_producy_id=67;
    QString arduino1_port_name;
    bool arduino1_is_available;
    QByteArray data;  // contenant les données lues à partir d'arduino1
};



#endif // ARDUINO1_H
