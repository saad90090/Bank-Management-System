#ifndef OPTIONS_H
#define OPTIONS_H
#include <QDialog>
#include "withdrawl.h"
#include "deposit.h"
#include "fundstransfer.h"
#include "changepin.h"
#include "changepword.h"
#include "accountstatement.h"
namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
