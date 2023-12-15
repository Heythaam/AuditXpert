#include "arduino2.h"

arduino2::arduino2()
{
    data="";
    arduino2_port_name="";
    arduino2_is_available=false;
    serial=new QSerialPort;
}

QString arduino2::getarduino2_port_name()//renvoie le nom du port arduino2.
{
    return arduino2_port_name;
}

QSerialPort *arduino2::getserial()//renvoie le pointeur vers l'objet QSerialPort.
{
   return serial;
}
int arduino2::connect_arduino2()
{   // recherche du port sur lequel la carte arduino2 identifée par  arduino2_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino2_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino2_uno_producy_id) {
                   arduino2_is_available = true;
                   arduino2_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino2_port_name is :" << arduino2_port_name;
        if(arduino2_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino2_port_name);
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

int arduino2::close_arduino2()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray arduino2::read_from_arduino2()//lit toutes les données disponibles du port série et les renvoie sous la forme d'un objet QByteArray.
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
     return data;
 }
 QByteArray arduino2::readL_from_arduino2()//lit  une ligne de données du port série et les renvoie sous la forme d'un objet QByteArray
 {
     QByteArray data;
     while (serial->canReadLine()) {
         data = serial->readLine();
     }
          return data;
     }



int arduino2::write_to_arduino2( QByteArray d)//écrit les données spécifiées dans le port série.

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers arduino2
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
