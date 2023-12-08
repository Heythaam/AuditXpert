#include "calendrier.h"
#include "ui_calendrier.h"
#include "amendes.h"
#include <qdebug.h>
#include <QMessageBox>
#include "numberformatdelegate.h"
calendrier::calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendrier)
{
    ui->setupUi(this);
    ui->tableCalendrier->setItemDelegateForColumn(0, new NumberFormatDelegate(0, this));
}

calendrier::~calendrier()
{
    delete ui;
}

void calendrier::on_Calendrier_clicked()
{
    QString date1 = ui->Calendrier->selectedDate().toString("dd/MM/yy");
    //QMessageBox::critical(nullptr, QObject::tr("not ok"),date1, QMessageBox::Cancel);
    ui->tableCalendrier->setModel(ETMP.calendrier(date1));
    //ui->label->setText(date1);
}
