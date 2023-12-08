#include "notifications.h"
#include "QApplication"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}
void notification::notification_ajoutNorme()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/icon_valide.png"));
   notifyIcon->show();
   notifyIcon->showMessage("Gestion des Normes ","nouveau Normes est ajouté ",QSystemTrayIcon::Information,15000);
    srand (time(NULL));
}

void notification::notification_supprimerNorme(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/icon_valide.png"));
   notifyIcon->show();
    notifyIcon->showMessage("Gestion des Normes","Normes est supprimé",QSystemTrayIcon::Information,15000);
srand (time(NULL));
}


void notification::notification_modifierNorme(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/icon_valide.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Normes ","Normes est modifié",QSystemTrayIcon::Information,15000);
srand (time(NULL));
}


void notification::notification_failed(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Normes ","action failed",QSystemTrayIcon::Critical,15000);
srand (time(NULL));
}



















