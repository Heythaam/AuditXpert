#ifndef INSERT_IMAGE_H
#define INSERT_IMAGE_H

#include <QDialog>

namespace Ui {
class insert_image;
}

class insert_image : public QDialog
{
    Q_OBJECT

public:
    explicit insert_image(QWidget *parent = nullptr);
    ~insert_image();

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::insert_image *ui;
};

#endif // INSERT_IMAGE_H
