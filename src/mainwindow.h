#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "amendes.h"
#include "normes.h"
#include "product.h"
#include "client.h"
#include "employer.h"
#include "modify_amendes.h"
#include "modify_normes.h"
#include "modify_produits.h"
#include "modify_clients.h"
#include "modify_employes.h"
#include "QtPrintSupport/qprinter.h"
#include "QtPrintSupport/QPrintDialog"
#include "qr_code.h"
#include "insert_image.h"
#include "qrcode.h"
#include "arduino.h"
#include "arduino1.h"
#include "arduino2.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_produits_clicked();

    void on_Button_normes_clicked();

    void on_Button_amendes_clicked();

    void on_ajouter_amendes_clicked();

    void on_tableView_amendes_activated(const QModelIndex &index);

    void on_Tri_amendes_clicked();

    void on_recherche_amendes_textChanged(const QString &arg1);

    void on_mail_amendes_clicked();

    void on_calendrier_amendes_clicked();

    void on_stats_amendes_clicked();

    void on_ajouter_normes_clicked();

    void on_tableView_normes_activated(const QModelIndex &index);

    void on_chatbot_normes_clicked();

    void on_PDF_9_clicked();

    void on_ajouter_produits_clicked();

    void on_tableView_produits_activated(const QModelIndex &index);

    void on_Tri_normes_clicked();

    void on_recherche_normes_textChanged(const QString &arg1);

    void on_qr_code_clicked();

    void on_recherche_produits_textChanged(const QString &arg1);

    void on_insert_image_clicked();

    void on_PDF_produits_clicked();

    void on_Tri_produits_clicked();

    void on_ajouter_clients_clicked();

    void on_tableView_client_activated(const QModelIndex &index);

    void on_recherche_clients_textChanged(const QString &arg1);

    void on_Tri_clients_clicked();

    void on_PDF_clients_clicked();

    void on_Button_amendes_2_clicked();

    void on_Button_clients_2_clicked();

    void on_Button_employes_2_clicked();

    void on_Button_normes_2_clicked();

    void on_Button_produits_2_clicked();

    void on_Button_amendes_3_clicked();

    void on_Button_clients_3_clicked();

    void on_Button_employes_3_clicked();

    void on_Button_normes_3_clicked();

    void on_Button_produits_3_clicked();

    void on_Button_amendes_4_clicked();

    void on_Button_clients_4_clicked();

    void on_Button_employes_4_clicked();

    void on_Button_normes_4_clicked();

    void on_Button_produits_4_clicked();

    void on_Button_amendes_5_clicked();

    void on_Button_clients_5_clicked();

    void on_Button_employes_5_clicked();

    void on_Button_normes_5_clicked();

    void on_Button_produits_5_clicked();

    void on_pushButton_6_clicked();

    void on_login_clicked();

    void on_ajouter_employes_clicked();

    void on_tableView_employe_activated(const QModelIndex &index);

    void on_recherche_employes_textChanged(const QString &arg1);

    void on_Tri_employes_clicked();

    void on_PDF_employes_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    //void on_stats_normes_clicked();

    void on_stats_employes_clicked();

    void on_stats_normes_clicked();

    void on_stats_clients_clicked();

    void on_stats_produits_clicked();

    void on_PDF_normes_clicked();

    void on_Button_clients_clicked();

    void on_Button_employes_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_register_2_clicked();

    //void on_pushButton_7_clicked();

    //void on_pushButton_8_clicked();


    void on_reset_password_clicked();

    void on_pushButton_3_clicked();

    void on_reset_clicked();

    void on_parking_clicked();

    void on_pushButton_4_clicked();

    void update_label();


    void on_PDF_produits_2_clicked();

    void on_stats_produits_2_clicked();

private:
    Ui::MainWindow *ui;
    amendes Etmp_amendes;
    Norme Etmp_normes;
    Product Etmp_produits;
    Client Etmp_client;
    Employer Etmp_employes;
    modify_amendes * d;
    modify_normes * d1;
    modify_produits * d2;
    modify_clients * d3;
    modify_employes * d4;
    Arduino A;
    arduino1 A1;
    arduino2 A2;

    Product etmp;

};
#endif // MAINWINDOW_H
