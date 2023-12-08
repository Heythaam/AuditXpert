#include "stats_amendes.h"
#include "ui_stats_amendes.h"

stats_amendes::stats_amendes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats_amendes)
{
    ui->setupUi(this);
}

stats_amendes::~stats_amendes()
{
    delete ui;
}



void stats_amendes::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT MONTANT FROM AMENDES");
    query.exec();


    int countunder1000 = 0;
    int count1000to5000 = 0;
    int countfrom5000 = 0;

    while (query.next())
    {
        float montantc= query.value("MONTANT").toFloat();

        if (montantc < 1000) {
            countunder1000++;
        } else if (montantc <= 5000) {
            count1000to5000++;
        } else {
            countfrom5000++;
        }
    }

    QPieSeries *series = new QPieSeries();
    series->append("Under 1000", countunder1000);
    series->append("1000 to 5000", count1000to5000);
    series->append("From 5000", countfrom5000++);

    QColor color1000to5000(50, 205, 50);
    series->slices().at(1)->setBrush(color1000to5000);
    series->slices().at(1)->setLabelColor(Qt::black);

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(QString::number(slice->percentage(), 'f', 1)));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Amount Statistics of Fines");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(420, 300);

    chartView->show();
}

