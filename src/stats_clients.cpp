#include "stats_clients.h"
#include "ui_stats_clients.h"
#include<QPieSeries>
#include <QSqlQuery>
#include "client.h"
#include <QChart>
#include <QChartView>
#include <QPieSlice>
#include <QtCharts>
#include <iostream>
#include <QApplication>
#include <QDebug>

stats_clients::stats_clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats_clients)
{
    ui->setupUi(this);
}

stats_clients::~stats_clients()
{
    delete ui;
}


void stats_clients::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT DOMAINECLIENT FROM CLIENTS");
    query.exec();

    int finance = 0;
    int IT = 0;
    int agriculture = 0;

    while (query.next())
    {
        QString domaine = query.value("DOMAINECLIENT").toString();

        // Categorize clients based on domain
        if (domaine == "finance") {
            finance++;
        } else if (domaine == "IT") {
            IT++;
        } else if (domaine == "agriculture") {
            agriculture++;
        }
    }

    qDebug() << "Data read from the database:";
    qDebug() << "Finance clients: " << finance;
    qDebug() << "IT clients: " << IT;
    qDebug() << "Agriculture clients: " << agriculture;

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();
    series->append("finance", finance);
    series->append("IT", IT);
    series->append("agriculture", agriculture);

    QColor colorIT(50, 205, 50);  // Lime Green
    series->slices().at(1)->setBrush(colorIT);
    series->slices().at(1)->setLabelColor(Qt::black);  // Black label for better visibility

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(QString::number(slice->percentage() * 100, 'f', 1)));
    }

    // Create a chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des domaines des clients");
    chart->legend()->hide();

    // Create a chart view
    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(420, 300);

    // Set the chart view as the central widget of the dialog
    chartView->show();
}
