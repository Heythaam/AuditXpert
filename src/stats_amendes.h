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

#ifndef STATS_AMENDES_H
#define STATS_AMENDES_H

#include <QDialog>

namespace Ui {
class stats_amendes;
}

class stats_amendes : public QDialog
{
    Q_OBJECT

public:
    explicit stats_amendes(QWidget *parent = nullptr);
    ~stats_amendes();
    void afficher();

private:
    Ui::stats_amendes *ui;
};

#endif // STATS_AMENDES_H
