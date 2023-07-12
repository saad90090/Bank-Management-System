#include "balance.h"
#include "ui_balance.h"

Balance::Balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
}

Balance::~Balance()
{
    delete ui;
}
