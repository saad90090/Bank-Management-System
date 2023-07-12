#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

namespace Ui {
class deposit;
}

class deposit : public QDialog
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
