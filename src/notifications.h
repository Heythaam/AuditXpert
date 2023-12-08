#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QCoreApplication>

#include <QSystemTrayIcon>
#include<QString>
class notification
{
public:
    notification();
    void notification_ajoutNorme();

    void notification_supprimerNorme();

    void notification_modifierNorme();

void notification_failed();


};



#endif // NOTIFICATION_H
