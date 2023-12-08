#ifndef STATS_PRODUITS_H
#define STATS_PRODUITS_H

#include <QDialog>
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
class stats_produits;
}

class stats_produits : public QDialog
{
    Q_OBJECT

public:
    explicit stats_produits(QWidget *parent = nullptr);
    ~stats_produits();
    void afficher();

private:
    Ui::stats_produits *ui;
};

#endif // STATS_PRODUITS_H
