#include "stats_normes.h"
#include "ui_stats_normes.h"

stats_normes::stats_normes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats_normes)
{
    ui->setupUi(this);
}

stats_normes::~stats_normes()
{
    delete ui;
}


void stats_normes::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT TYPE_NORME FROM NORMES");
    query.exec();

    int finance = 0;
    int IT = 0;
    int agriculture = 0;

    while (query.next())
    {
        QString domaine = query.value("TYPE_NORME").toString();

        // Categorize clients based on domain
        if (domaine == "IFRS") {
            finance++;
        } else if (domaine == "IAS") {
            IT++;
        } else if (domaine == "IASB") {
            agriculture++;
        }
    }

    qDebug() << "Data read from the database:";
    qDebug() << "IFRS: " << finance;
    qDebug() << "IAS: " << IT;
    qDebug() << "IASB: " << agriculture;

    // Create a pie chart series
    QPieSeries *series = new QPieSeries();
    series->append("IFRS", finance);
    series->append("IAS", IT);
    series->append("IASB", agriculture);

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
    chart->setTitle("Statistiques des types de normes dans les données");
    chart->legend()->hide();

    // Create a chart view
    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(420, 300);

    // Set the chart view as the central widget of the dialog
    chartView->show();
}
