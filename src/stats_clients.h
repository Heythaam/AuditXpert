#ifndef STATS_CLIENTS_H
#define STATS_CLIENTS_H

#include <QDialog>

namespace Ui {
class stats_clients;
}

class stats_clients : public QDialog
{
    Q_OBJECT

public:
    explicit stats_clients(QWidget *parent = nullptr);
    ~stats_clients();
    void afficher();

private:
    Ui::stats_clients *ui;
};

#endif // STATS_CLIENTS_H
