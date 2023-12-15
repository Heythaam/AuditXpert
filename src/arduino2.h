#ifndef ARDUINO2_H
#define ARDUINO2_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class arduino2
{
public:     //méthodes de la classe arduino2
    arduino2();
    int connect_arduino2(); // permet de connecter le PC à arduino2
    int close_arduino2(); // permet de femer la connexion
    int write_to_arduino2( QByteArray ); // envoyer des données vers arduino2
    QByteArray read_from_arduino2();
    QByteArray readL_from_arduino2();//recevoir des données de la carte arduino2
    QSerialPort* getserial();   // accesseur
    QString getarduino2_port_name();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour arduino2.
    static const quint16 arduino2_uno_vendor_id=9025;
    static const quint16 arduino2_uno_producy_id=67;
    QString arduino2_port_name;
    bool arduino2_is_available;
    QByteArray data;  // contenant les données lues à partir d'arduino2
};



#endif // ARDUINO2_H
