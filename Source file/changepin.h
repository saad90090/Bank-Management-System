#ifndef CHANGEPIN_H
#define CHANGEPIN_H

#include <QDialog>

namespace Ui {
class changepin;
}

class changepin : public QDialog
{
    Q_OBJECT

public:
    explicit changepin(QWidget *parent = nullptr);
    ~changepin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::changepin *ui;
};

#endif // CHANGEPIN_H
