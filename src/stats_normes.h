#ifndef STATS_NORMES_H
#define STATS_NORMES_H

#include <QDialog>
#include "normes.h"
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QtCharts>
#include <iostream>
#include <iostream>
namespace Ui {
class stats_normes;
}

class stats_normes : public QDialog
{
    Q_OBJECT

public:
    explicit stats_normes(QWidget *parent = nullptr);
    ~stats_normes();
    void afficher();

private:
    Ui::stats_normes *ui;
};

#endif // STATS_NORMES_H
