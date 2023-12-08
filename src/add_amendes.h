#ifndef ADD_AMENDES_H
#define ADD_AMENDES_H

#include <QDialog>

namespace Ui {
class add_amendes;
}

class add_amendes : public QDialog
{
    Q_OBJECT

public:
    explicit add_amendes(QWidget *parent = nullptr);
    ~add_amendes();

private:
    Ui::add_amendes *ui;
private slots:
    void on_b_ajouter_amendes_clicked();
};

#endif // ADD_AMENDES_H
