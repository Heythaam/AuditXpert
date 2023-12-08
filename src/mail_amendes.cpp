#include "mail_amendes.h"
#include "ui_mail_amendes.h"
#include "smtp.h"
#include <qmessagebox.h>
mail_amendes::mail_amendes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail_amendes)
{
    ui->setupUi(this);
}

mail_amendes::~mail_amendes()
{
    delete ui;
}

void mail_amendes::on_SEND_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);


        smtp.setUser("auditxpert1@gmail.com");
        smtp.setPassword("mkuv bnja tukk pkgd");


        MimeMessage message;
        QString res= ui->recepient->text();
        message.setSender(new EmailAddress("auditxpert1@gmail.com", "AuditXpert"));
        message.addRecipient(new EmailAddress(res, "Client"));
        QString res2= ui->Object->text();
        message.setSubject(res2);


        MimeText text;
        QString res1=ui->body->toPlainText();
        text.setText(res1);

        message.addPart(&text);


        smtp.connectToHost();

        smtp.login();

        if (smtp.sendMail(message)){
            QMessageBox::information(nullptr, QObject::tr("success"),
                                     QObject::tr("Email sent!\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("failed"),
                                     QObject::tr("failed!!\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

        smtp.quit();
        }



