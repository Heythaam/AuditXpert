#ifndef ADD_H
#define ADD_H

#include <QDialog>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_b_ajouter_clicked();

private:
    Ui::add *ui;
    int x;
};

#endif // ADD_H
