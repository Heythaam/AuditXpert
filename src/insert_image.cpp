#include "insert_image.h"
#include "ui_insert_image.h"
#include "qfiledialog.h"
insert_image::insert_image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_image)
{
    ui->setupUi(this);
}

insert_image::~insert_image()
{
    delete ui;
}

void insert_image::on_pushButton_9_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"),"", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);

        if (valid)
        {
            image = image.scaledToWidth(ui->label_8->width(), Qt::SmoothTransformation);
            image = image.scaledToHeight(ui->label_8->height(), Qt::SmoothTransformation);
            ui->label_8->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error

        }
    }
}
