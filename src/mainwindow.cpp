#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_amendes.h"
#include "add_normes.h"
#include "add_client.h"
#include "add_employes.h"
#include "employer.h"
#include "numberformatdelegate.h"
#include "modify_amendes.h"
#include "ui_modify_amendes.h"
#include "modify_normes.h"
#include "ui_modify_normes.h"
#include "modify_produits.h"
#include "ui_modify_produits.h"
#include "modify_clients.h"
#include "ui_modify_clients.h"
#include "modify_employes.h"
#include "ui_modify_employes.h"
#include "mail_amendes.h"
#include "calendrier.h"
#include "stats_amendes.h"
#include "chatbot.h"
#include "add_produits.h"
//#include "dialogstat.h"
#include "stats.h"
#include "stats_normes.h"
#include "stats_clients.h"
#include "stats_produits.h"
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*                                          PARTIE AMENDES                                          */
    ui->tableView_amendes->setModel(Etmp_amendes.afficher());
    ui->tableView_amendes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_amendes->setItemDelegateForColumn(0, new NumberFormatDelegate(0, this));
    ui->tableView_amendes->setItemDelegateForColumn(2, new NumberFormatDelegate(0, this));
    /*                                          PARTIE NORMES                                          */
    ui->tableView_normes->setModel(Etmp_normes.afficher());
    ui->tableView_normes->setSelectionBehavior(QAbstractItemView::SelectRows);
    QSystemTrayIcon trayIcon(QIcon("C:/Users/Heytham/Desktop/qt/integration_finale/notification.jpg"));
    trayIcon.setVisible(true);

    QSqlQuery query13;
    query13.prepare("SELECT * FROM Normes WHERE Date_F_Norme = :Date_F_Norme");
    query13.bindValue(":Date_F_Norme", QDate::currentDate().addDays(2));

    if (query13.exec()) {
        while (query13.next()) {
            QDate dateFinNorme = query13.value(5).toDate();  // Assuming the column index for the date is correct (adjust if needed)
            int Numero = query13.value(0).toInt();

            if (dateFinNorme <= QDate::currentDate().addDays(2)) {
                trayIcon.show();
                trayIcon.showMessage("News", "La date de fin de norme  N°:" + QString::number(Numero) + " s'approche (" + dateFinNorme.toString("dd-MM-yyyy") + ")", QSystemTrayIcon::Information, 15000);
            }
        }


    }
    ui->tableView_normes->setItemDelegateForColumn(2, new NumberFormatDelegate(0, this));
    /*                                          PARTIE PRODUITS                                          */
    QRegExp rx("regex");
    ui->tableView_produits->setSelectionBehavior(QAbstractItemView::SelectRows);
    QValidator *validator = new QRegExpValidator(rx, this);
    QLineEdit *edit = new QLineEdit(this);
    edit->setValidator(validator);
    ui->tableView_produits->setModel(Etmp_produits.displayProducts("ID"));
    ui->tableView_produits->setItemDelegateForColumn(0, new NumberFormatDelegate(0, this));
    ui->tableView_produits->setItemDelegateForColumn(2, new NumberFormatDelegate(0, this));
    ui->tableView_produits->setItemDelegateForColumn(3, new NumberFormatDelegate(0, this));
    /*                                          PARTIE CLIENTS                                         */
    ui->tableView_client->setModel(Etmp_client.afficher());
    ui->tableView_client->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_employe->setModel(Etmp_employes.afficher());
    ui->tableView_employe->setSelectionBehavior(QAbstractItemView::SelectRows);
    QValidator* IDValidator = new QRegExpValidator(QRegExp("[0-9]+"));
    QValidator* TextValidator = new QRegExpValidator(QRegExp("[A-Za-z ]+"));
    QValidator* MailValidator = new QRegExpValidator(QRegExp("[A-Za-z0-9._]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"));
/////////////////CREATE/////////////////
    ui->le_id->setValidator(IDValidator);
    ui->le_id->setMaxLength(8);
    ui->le_nom->setValidator(TextValidator);
    ui->le_nom->setMaxLength(20);
    ui->le_mail->setValidator(MailValidator);
    ui->le_mail->setMaxLength(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button_client_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_produits_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Button_normes_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button_amendes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_amendes_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_clients_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_employes_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button_normes_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button_produits_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Button_amendes_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_clients_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_employes_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button_normes_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button_produits_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Button_amendes_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_clients_4_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_employes_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button_normes_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button_produits_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Button_amendes_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_clients_5_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_employes_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button_normes_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button_produits_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
// //////////////////////////////////////AMENDES//////////////////////////////////////////////////////////////

void MainWindow::on_ajouter_amendes_clicked()
{
    add_amendes add_a;
    add_a.exec();
    ui->tableView_amendes->setModel(Etmp_amendes.afficher());
}

void MainWindow::on_tableView_amendes_activated(const QModelIndex &index)
{
    int row = ui->tableView_amendes->selectionModel()->currentIndex().row();
    d = new modify_amendes(this);
    QString ID_AMENDE= ui->tableView_amendes->model()->data(ui->tableView_amendes->model()->index(row,0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM amendes WHERE ID_AMENDE = :ID_AMENDE");
    query.bindValue(":ID_AMENDE", ID_AMENDE);
    if(query.exec()){
        while(query.next()){
            d->getUi()->le_id_u_amendes->setText(query.value(0).toString());
            d->getUi()->le_nom_u_amendes->setText(query.value(1).toString());
            d->getUi()->le_montant_u_amendes->setText(query.value(2).toString());
            d->getUi()->le_date_u_amendes->setDate(query.value(3).toDate());
            d->exec();
            ui->tableView_amendes->setModel(Etmp_amendes.afficher());
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
}

void MainWindow::on_Tri_amendes_clicked()
{
    ui->tableView_amendes->setModel(Etmp_amendes.afficherTri());
}

void MainWindow::on_recherche_amendes_textChanged(const QString &arg1)
{
    ui->tableView_amendes->setModel(Etmp_amendes.rechercher(ui->recherche_amendes->text()));
}



void MainWindow::on_mail_amendes_clicked()
{
    mail_amendes mail;
    mail.exec();
}

void MainWindow::on_calendrier_amendes_clicked()
{
   calendrier c;
   c.exec();
}

void MainWindow::on_stats_amendes_clicked()
{

       stats_amendes d;
       d.afficher();
       d.exec();
}

void MainWindow::on_PDF_9_clicked()
{
    QString strStream,strTitle;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_amendes->model()->rowCount();
    const int columnCount = ui->tableView_amendes->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>Amendes</title>\n").arg(strTitle)
        <<  "<head> Les amendes non payés</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2 style='width:100%;'>\n";

    // headers
    out << "h1 {" <<
            "   text-align: center;" // Center-align the h1 element
           << "}";
    out << "<h1> Liste des amendes</h1>";
    out << "<br>";
    out << "<br>";
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_amendes->isColumnHidden(column))
            out << "<th>" << ui->tableView_amendes->model()->headerData(column, Qt::Horizontal).toString() << "</th>";
    out << "</tr></thead>\n";


    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_amendes->isColumnHidden(column)) {
                QString data = ui->tableView_amendes->model()->data(ui->tableView_amendes->model()->index(row, column)).toString().simplified();
                out << QString("<td style='width:200px' bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;

}


// //////////////////////////////////////NORMES//////////////////////////////////////////////////////////////



void MainWindow::on_ajouter_normes_clicked()
{
    add_normes add_n;
    add_n.exec();
    ui->tableView_normes->setModel(Etmp_normes.afficher());
}

void MainWindow::on_tableView_normes_activated(const QModelIndex &index)
{
    int row = ui->tableView_normes->selectionModel()->currentIndex().row();
    d1 = new modify_normes(this);
    QString ID_Norme= ui->tableView_normes->model()->data(ui->tableView_normes->model()->index(row,0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM NORMES WHERE ID_NORME = :ID_NORME");
    query.bindValue(":ID_NORME", ID_Norme);
    if(query.exec()){
        while(query.next()){
            d1->getUi()->le_id_u_normes->setText(query.value(0).toString());
            d1->getUi()->le_type_u_normes->setText(query.value(1).toString());
            d1->getUi()->le_sector_u_normes->setText(query.value(2).toString());
            d1->getUi()->le_validity_u_normes->setText(query.value(2).toString());
            d1->getUi()->le_date_u_normes->setDate(query.value(3).toDate());
            d1->exec();
            ui->tableView_normes->setModel(Etmp_normes.afficher());
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
}

void MainWindow::on_chatbot_normes_clicked()
{
    chatbot chatbot;
    chatbot.exec();
}

void MainWindow::on_Tri_normes_clicked()
{
    ui->tableView_normes->setModel(Etmp_normes.triID());
}

void MainWindow::on_recherche_normes_textChanged(const QString &arg1)
{
    ui->tableView_normes->setModel(Etmp_normes.rechercher(ui->recherche_normes->text()));
}


// //////////////////////////////////////PRODUITS//////////////////////////////////////////////////////////////


void MainWindow::on_ajouter_produits_clicked()
{
    add_produits add_p;
    add_p.exec();
    ui->tableView_produits->setModel(Etmp_produits.displayProducts("ID"));
}

void MainWindow::on_tableView_produits_activated(const QModelIndex &index)
{
    int row = ui->tableView_produits->selectionModel()->currentIndex().row();
    d2 = new modify_produits(this);
    QString ID_PRODUITS= ui->tableView_produits->model()->data(ui->tableView_client->model()->index(row,0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUCTS WHERE ID = :ID");
    query.bindValue(":ID", ID_PRODUITS);
    if(query.exec()){
        while(query.next()){
            d2->getUi()->le_id_u_produits->setText(query.value(0).toString());
            d2->getUi()->le_nom_u_produits->setText(query.value(1).toString());
            d2->getUi()->le_prix_u_produits->setText(query.value(2).toString());
            d2->getUi()->le_quantity_u_produits->setText(query.value(3).toString());
            d2->exec();
            ui->tableView_produits->setModel(Etmp_produits.displayProducts("ID"));
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
}



void MainWindow::on_qr_code_clicked()
{
    qr_code qr;
    qr.exec();
}

void MainWindow::on_recherche_produits_textChanged(const QString &searchTerm)
{
    QString query = "SELECT * FROM PRODUCTS WHERE NAME LIKE '%" + searchTerm + "%'";

       QSqlQueryModel* model = new QSqlQueryModel();
       model->setQuery(query);
       ui->tableView_produits->setModel(model);
}



void MainWindow::on_insert_image_clicked()
{
    insert_image img;
    img.exec();
}

void MainWindow::on_PDF_produits_clicked()
{
        QSqlDatabase db = QSqlDatabase::database();


            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPageSize(QPageSize(QPageSize::A4));
            printer.setOutputFileName("Products.pdf");


            QPainter painter(&printer);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setRenderHint(QPainter::TextAntialiasing);


            QSqlQuery query("SELECT * FROM PRODUCTS", db);


            QTextDocument doc;
            doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point));
            QString styleSheet =
                                 "table { margin:10px;width: 90%; border-collapse: collapse; border-spacing: 0; font-family: Arial, sans-serif; font-size: 14px; color: #333; }"
                                 "table thead { background-color: ##9b3e3d; color: #fff; }"
                                 "h1 {font-family: 'Poppins', sans-serif;font-weight: 700;font-size: 30px;color: #9b3e3d;text-transform: uppercase;letter-spacing: 4px;text-align: center;margin-top: 50px;}"
                                 "h2 {font-family: 'Poppins', sans-serif;font-weight: 300;font-size: 30px;color: #9b3e3d;text-transform: uppercase;letter-spacing: 4px;text-align: center;}"
                    /* espacement */
                    "table {table-layout: fixed;width: 100%;border-collapse: collapse;border: 3px solid purple;}"
                    "thead th:nth-child(1) {width: 30%;}"
                    "thead th:nth-child(2) {width: 20%;}"
                    "thead th:nth-child(3) {width: 15%;}"
                    "thead th:nth-child(4) {width: 35%;}"
                    "th,td {padding: 20px;}";
            doc.setDefaultStyleSheet(styleSheet);
            QImage image("C:/Users/Adem/Desktop/product/product/pictures/logo.png");
            QRect rect(200, 0, 200, 200); // Set the position and size of the image
            painter.drawImage(rect, image);




            QString html = "<center><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><h2>auditXpert</h2><hr><h1>Liste of products</h1><table><thead><tr><th>Id</th><th>Name</th><th>Price</th><th>Quantity</th></tr></thead><tbody>";
            while (query.next()) {
                QString ID = query.value(0).toString();
                QString Name = query.value(1).toString();
                QString Price = query.value(2).toString();
                QString Quantity= query.value(3).toString();


               html += "<tr><td>" + ID + "</td><td>" + Name + "</td><td>" + Price + "</td><td>" + Quantity + "</td>";
            }
            html += "</tbody></table>";
            doc.setHtml(html);


            doc.drawContents(&painter);
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Export PDF successful."), QMessageBox::Cancel);

            // Cleanup
            painter.end();

}

void MainWindow::on_Tri_produits_clicked()
{
    ui->tableView_produits->setModel(Etmp_produits.afficherTri());
}

// //////////////////////////////////////CLIENTS//////////////////////////////////////////////////////////////

void MainWindow::on_ajouter_clients_clicked()
{
    add add_c;
    add_c.exec();
    ui->tableView_client->setModel(Etmp_client.afficher());
}

void MainWindow::on_tableView_client_activated(const QModelIndex &index)
{
    int row = ui->tableView_client->selectionModel()->currentIndex().row();
    d3 = new modify_clients(this);
    QString ID_CLIENTS= ui->tableView_client->model()->data(ui->tableView_client->model()->index(row,0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE IDCLIENT = :IDCLIENT");
    query.bindValue(":IDCLIENT", ID_CLIENTS);
    if(query.exec()){
        while(query.next()){
            d3->getUi()->le_id_u_clients->setText(query.value(0).toString());
            d3->getUi()->le_nom_u_clients->setText(query.value(1).toString());
            d3->getUi()->le_domaine_u_clients->setText(query.value(2).toString());
            d3->getUi()->le_date_u_clients->setDate(query.value(3).toDate());
            d3->exec();
            ui->tableView_client->setModel(Etmp_client.afficher());
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
}

void MainWindow::on_recherche_clients_textChanged(const QString &arg1)
{
    QString nom=ui->recherche_clients->text();
    ui->tableView_client->setModel(Etmp_client.recherchernom(nom));
}

void MainWindow::on_Tri_clients_clicked()
{
    ui->tableView_client->setModel(Etmp_client.triID());
}

void MainWindow::on_PDF_clients_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    QPdfWriter pdf(dir+"/Client.pdf");

        QPainter painter(&pdf);
                int i = 4000;
                painter.setPen(Qt::black);
                painter.setFont(QFont("Arial", 30));
                painter.drawText(1200,1200,"Liste des Clients");
                painter.setPen(Qt::black);
                painter.setFont(QFont("Arial", 50));
                painter.drawPixmap(QRect(4400,1200,918,1027),QPixmap("C:/Users/Heytham/Desktop/qt/integration_finale/gfx/logo-audit.png"));
                painter.drawRect(0,3000,9600,500);
                painter.setFont(QFont("Arial", 9));
                painter.setPen(Qt::blue);
                painter.drawText(300,3300,"ID");
                painter.drawText(2300,3300,"Nom");
                painter.drawText(4300,3300,"Domaine");
                painter.drawText(6300,3300,"Date");

                QSqlQuery query;
                query.prepare("SELECT * FROM CLIENTS");
                query.exec();
                while (query.next())
                {
                    painter.drawText(300,i,query.value(0).toString());
                    painter.drawText(2300,i,query.value(1).toString());
                    painter.drawText(4300,i,query.value(2).toString());
                    painter.drawText(6300,i,query.value(3).toString());
                    i = i +500;
                }



                    int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
                    if (reponse == QMessageBox::Yes)
                    {
                        QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Client.pdf"));
                        painter.end();
                    }
                    else
                    {
                        painter.end();
                    }




        QFile file("C:/Users/Heytham/Desktop/qt/integration_finale/historique.txt");
        if(!file.open(QIODevice::Append | QIODevice::Text)){

            qDebug() << "Erreur.";
        }

        QDateTime dateTime=QDateTime::currentDateTime();
        QTextStream outFile(&file);

        outFile << "Evenement : Generation d'un PDF | Date : " << dateTime.toString() <<"\n";
        file.close();
}


void MainWindow::on_login_clicked()
{
    QString log=ui->username->text();
    QString pass=ui->password->text();
    QString poste;
        if(Etmp_employes.search(log,pass,poste)){
            QMessageBox::information(nullptr, QObject::tr("Connected successfully"),QObject::tr("Welcome\n"),QMessageBox::Ok);
            if (poste == "admin")
            {
            ui->stackedWidget->setCurrentIndex(0);
            }
            else if (poste == "employe")
            {
            ui->stackedWidget->setCurrentIndex(1);
            ui->Button_employes->setDisabled(1);
            ui->Button_employes_5->setDisabled(1);
            ui->Button_employes_4->setDisabled(1);
            ui->Button_employes_3->setDisabled(1);
            }
               ui->username->clear();
               ui->password->clear();

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Connected error"),QObject::tr("Check your login\n"),QMessageBox::Ok);
        }
}


// //////////////////////////////////////EMPLOYES//////////////////////////////////////////////////////////////

void MainWindow::on_ajouter_employes_clicked()
{
 add_employes add_e;
 add_e.exec();
 ui->tableView_employe->setModel(Etmp_employes.afficher());
}

void MainWindow::on_tableView_employe_activated(const QModelIndex &index)
{
    int row = ui->tableView_employe->selectionModel()->currentIndex().row();
    d4 = new modify_employes(this);
    QString ID_EMPLOYE= ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(row,0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE ID_EMPLOYE = :ID_EMPLOYE");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    if(query.exec()){
        while(query.next()){
            d4->getUi()->le_id->setText(query.value(0).toString());
            d4->getUi()->le_nom->setText(query.value(1).toString());
            d4->getUi()->age_add_employe->setText(query.value(7).toString());
            d4->getUi()->le_mail->setText(query.value(3).toString());
            d4->getUi()->password_add->setText(query.value(6).toString());
            d4->getUi()->le_role->setText(query.value(2).toString());
            d4->getUi()->time_start_add->setTime(query.value(4).toTime());
            d4->getUi()->time_finish_add->setTime(query.value(5).toTime());
            d4->exec();
            ui->tableView_employe->setModel(Etmp_employes.afficher());
        }
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("update failed\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        hide();
    }
}


void MainWindow::on_recherche_employes_textChanged(const QString &arg1)
{
    QString nom=ui->recherche_employes->text();
    ui->tableView_employe->setModel(Etmp_employes.rechercher(nom));
}

void MainWindow::on_Tri_employes_clicked()
{
    ui->tableView_employe->setModel(Etmp_employes.afficherTriID());
}

void MainWindow::on_PDF_employes_clicked()
{
    QString strStream,strTitle;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_employe->model()->rowCount();
        const int columnCount = ui->tableView_employe->model()->columnCount()-1;

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>Employés</title>\n").arg(strTitle)
            <<  "<head> Les Employés </head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2 style='width:100%;'>\n";

        // headers
        out << "h1 {" <<
                "   text-align: center;" // Center-align the h1 element
               << "}";
        out << "<h1> Liste Des Employés </h1>";
        out << "<br>";
        out << "<br>";
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_employe->isColumnHidden(column))
                out << "<th>" << ui->tableView_employe->model()->headerData(column, Qt::Horizontal).toString() << "</th>";
        out << "</tr></thead>\n";


        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_employe->isColumnHidden(column)) {
                    QString data = ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(row, column)).toString().simplified();
                    out << QString("<td style='width:200px' bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

/*void MainWindow::on_stats_normes_clicked()
{
       Dialogstat stat_normes;
       stat_normes.exec();
}*/

void MainWindow::on_stats_employes_clicked()
{
    stats stats_employe;
    stats_employe.afficher();
    stats_employe.exec();
}

void MainWindow::on_stats_normes_clicked()
{
    stats_normes stats_n;
    stats_n.afficher();
    stats_n.exec();
}

void MainWindow::on_stats_clients_clicked()
{
    stats_clients stats_c;
    stats_c.afficher();
    stats_c.exec();
}

void MainWindow::on_stats_produits_clicked()
{
    stats_produits stats_p;
    stats_p.afficher();
    stats_p.exec();
}

void MainWindow::on_PDF_normes_clicked()
{
 QString strStream,strTitle;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_normes->model()->rowCount();
    const int columnCount = ui->tableView_normes->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>Normes</title>\n").arg(strTitle)
        <<  "<head> Les Normes non payés</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2 style='width:100%;'>\n";

    // headers
    out << "h1 {" <<
            "   text-align: center;" // Center-align the h1 element
           << "}";
    out << "<h1> Liste des Normes</h1>";
    out << "<br>";
    out << "<br>";
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_normes->isColumnHidden(column))
            out << "<th>" << ui->tableView_normes->model()->headerData(column, Qt::Horizontal).toString() << "</th>";
    out << "</tr></thead>\n";


    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_normes->isColumnHidden(column)) {
                QString data = ui->tableView_normes->model()->data(ui->tableView_normes->model()->index(row, column)).toString().simplified();
                out << QString("<td style='width:200px' bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;

}

void MainWindow::on_Button_clients_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Button_employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_register_2_clicked()
{
    {

     QString id=ui->le_id->text();
     QString nom=ui->le_nom->text();
     QString poste=ui->le_role->text();
     QString mail=ui->le_mail->text();
     QString password=ui->password_add->text();
     QTime starttime(8,0,0);
     QTime endtime(17,0,0);
     int age=ui->age_add_employe->text().toInt();
      Employer E(id,nom,poste,mail,starttime,endtime,password,age);
      if (E.ajouter())
          {
          SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);


              smtp.setUser("auditxpert1@gmail.com");
              smtp.setPassword("mkuv bnja tukk pkgd");


              MimeMessage message;
              QString res= ui->le_mail->text();
              message.setSender(new EmailAddress("auditxpert1@gmail.com", "AuditXpert"));
              message.addRecipient(new EmailAddress(res, "Client"));
              message.setSubject("Account Creation Confirmation");


              MimeText text;
              res= "Dear "+ui->le_nom->text()+",\n\nThank you creating an account with AuditXpert!\n\nYour account has been successfully created. Here are your account details: \n\nUsername: "+ui->le_nom->text()+"\nEmail: "+ui->le_mail->text()+"\n\nIf you have any questions or need assistance, please feel free to contact our support team.\n\nBest regards,\nAuditXpert Team";
              text.setText(res);

              message.addPart(&text);


              smtp.connectToHost();

              smtp.login();

              if (smtp.sendMail(message)){
                  QMessageBox::information(nullptr, QObject::tr("Account Creation Success"),
                                           QObject::tr("An email has been sent for more details.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
              }
              else{
                  QMessageBox::critical(nullptr, QObject::tr("failed"),
                                           QObject::tr("failed!!\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
              }

              smtp.quit();

          }
          else{
              QMessageBox::critical(nullptr, QObject::tr("Error"),QObject::tr("Add Failed\n"),QMessageBox::Close);
          }
    }
}
