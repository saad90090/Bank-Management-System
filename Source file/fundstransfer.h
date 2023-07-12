#ifndef FUNDSTRANSFER_H
#define FUNDSTRANSFER_H

#include <QDialog>
extern QString username;
namespace Ui {
class Fundstransfer;
}

class Fundstransfer : public QDialog
{
    Q_OBJECT

public:
    explicit Fundstransfer(QWidget *parent = nullptr);
    ~Fundstransfer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_accountnum_editingFinished();

    void on_amount_editingFinished();

    void on_lineEdit_editingFinished();

private:
    Ui::Fundstransfer *ui;
};

#endif // FUNDSTRANSFER_H
