#ifndef ACCOUNTSTATEMENT_H
#define ACCOUNTSTATEMENT_H

#include <QDialog>

namespace Ui {
class Accountstatement;
}

class Accountstatement : public QDialog
{
    Q_OBJECT

public:
    explicit Accountstatement(QWidget *parent = nullptr);
    ~Accountstatement();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Accountstatement *ui;
};

#endif // ACCOUNTSTATEMENT_H
