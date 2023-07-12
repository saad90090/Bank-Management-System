#ifndef WITHDRAWL_H
#define WITHDRAWL_H

#include <QDialog>

extern QString username;
namespace Ui {
class withdrawl;
}

class withdrawl : public QDialog
{
    Q_OBJECT

public:
    explicit withdrawl(QWidget *parent = nullptr);
    ~withdrawl();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

    void on_pin_editingFinished();

private:
    Ui::withdrawl *ui;
};

#endif // WITHDRAWL_H
