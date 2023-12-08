#ifndef CALENDRIER_H
#define CALENDRIER_H
#include "amendes.h"
#include <QDialog>
#include <qcalendarwidget.h>
namespace Ui {
class calendrier;
}

class calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();

private slots:
    void on_Calendrier_clicked();

private:
    Ui::calendrier *ui;
    amendes ETMP;
};

#endif // CALENDRIER_H
