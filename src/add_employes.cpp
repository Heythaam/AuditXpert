#include "add_employes.h"
#include "ui_add_employes.h"

add_employes::add_employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_employes)
{
    ui->setupUi(this);

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

add_employes::~add_employes()
{
    delete ui;
}

void add_employes::on_b_ajouter_employes_clicked()
{

 QString id=ui->le_id->text();
 QString nom=ui->le_nom->text();
 QString poste=ui->le_role->text();
 QString mail=ui->le_mail->text();
 QString password=ui->password_add->text();
 QTime starttime=ui->time_start_add->time();
 QTime endtime=ui->time_finish_add->time();
 int age=ui->age_add_employe->text().toInt();
  Employer E(id,nom,poste,mail,starttime,endtime,password,age);
  if (E.ajouter())
      {
          QMessageBox::information(nullptr, QObject::tr("Success"),QObject::tr("Add Succesfull.\n"), QMessageBox::Ok);

      }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Error"),QObject::tr("Add Failed\n"),QMessageBox::Close);
      }
}
