#include "arduino1.h"

arduino1::arduino1()
{
    data="";
    arduino1_port_name="";
    arduino1_is_available=false;
    serial=new QSerialPort;
}

QString arduino1::getarduino1_port_name()//renvoie le nom du port arduino1.
{
    return arduino1_port_name;
}

QSerialPort *arduino1::getserial()//renvoie le pointeur vers l'objet QSerialPort.
{
   return serial;
}
int arduino1::connect_arduino1()
{   // recherche du port sur lequel la carte arduino1 identifée par  arduino1_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino1_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino1_uno_producy_id) {
                   arduino1_is_available = true;
                   arduino1_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino1_port_name is :" << arduino1_port_name;
        if(arduino1_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino1_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int arduino1::close_arduino1()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray arduino1::read_from_arduino1()//lit toutes les données disponibles du port série et les renvoie sous la forme d'un objet QByteArray.
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
     return data;
 }

 QByteArray arduino1::readL_from_arduino1()//lit  une ligne de données du port série et les renvoie sous la forme d'un objet QByteArray
 {
     QByteArray data;
     while (serial->canReadLine()) {
         data = serial->readLine();
     }
          return data;
     }



int arduino1::write_to_arduino1( QByteArray d)//écrit les données spécifiées dans le port série.

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers arduino1
    }else{
        qDebug() << "Couldn't write to serial!";
    }

}
