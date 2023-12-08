#include "stats.h"
#include "ui_stats.h"

stats::stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}


void stats::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT AGE FROM EMPLOYES");
    query.exec();


    int countunder20 = 0;
    int count20to30 = 0;
    int countfrom30 = 0;

    while (query.next())
    {
        float ages= query.value("AGE").toFloat();

        if (ages < 20) {
            countunder20++;
        } else if (ages <= 30) {
            count20to30++;
        } else {
            countfrom30++;
        }
    }

    QPieSeries *series = new QPieSeries();
    series->append("Under 20", countunder20);
    series->append("20 to 30", count20to30);
    series->append("From 30", countfrom30++);

    QColor color20to30(50, 205, 50);
    series->slices().at(1)->setBrush(color20to30);
    series->slices().at(1)->setLabelColor(Qt::black);

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(QString::number(slice->percentage(), 'f', 1)));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Age Statistics");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(420, 300);

    chartView->show();
}
