#include <QSqlQuery>
#include "amendes.h"
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QtCharts>
#include <iostream>
#include <iostream>

#ifndef STATS_H
#define STATS_H

#include <QDialog>

namespace Ui {
class stats;
}

class stats : public QDialog
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    ~stats();
    void afficher();

private:
    Ui::stats *ui;
};

#endif // STATS_H




