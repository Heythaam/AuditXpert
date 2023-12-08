#include "chatbot.h"
#include "ui_chatbot.h"
#include "normes.h"
chatbot::chatbot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatbot)
{
    ui->setupUi(this);
}

chatbot::~chatbot()
{
    delete ui;
}

void chatbot::on_pushButton_clicked()
{
    QString text,space="";
    float rassemblance=0;
    int tr=0;
    QString msg=ui->inputChatbot->text();
    ui->chatBot->appendPlainText(space);
    ui->chatBot->appendPlainText(msg);
    QSqlQuery qry,query;

     if(msg[0]!="#")
     {
        qry.prepare("select * from chatbot" );
        qry.exec();
        while(qry.next() && tr==0)
        {
            QString quest = qry.value(0).toString();
                int eq = 0,dif = 0;
                for(int i=0 ; i < msg.size(); i++)
                {
                       if(quest[i] == msg[i])
                           eq++;
                       else
                           dif++;
                }
                rassemblance = (eq / static_cast<float>(msg.size()))*100;
                if(rassemblance > 80)
                {
                    ui->chatBot->appendPlainText( "\n"+qry.value(1).toString());
                    tr=1;
                }
         }
        if(tr == 0)
        {

                ui->chatBot->appendPlainText( "Voulez vous ajouter un nouveau mot ? Écrivez votre réponse avec un # au début.");
                //ui->labelCache->setText(msg);

        }
     }
     else if (msg[0]=="#"){
         QString msg1=msg.mid(1,msg.length()-1);
         query.prepare("insert into chatbot (quest,rep)""values(:quest,:rep)");
         //query.bindValue(":quest", ui->labelCache->text());
         query.bindValue(":rep", msg1);
         query.exec();
         ui->chatBot->appendPlainText( "\n Merci ! Pour cette information");
     }
}
