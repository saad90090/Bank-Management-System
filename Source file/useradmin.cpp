#include "useradmin.h"
#include "ui_useradmin.h"

Useradmin::Useradmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Useradmin)
{
    ui->setupUi(this);
}

Useradmin::~Useradmin()
{
    delete ui;
}
