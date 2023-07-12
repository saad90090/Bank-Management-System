#include "options.h"
#include "ui_options.h"
#include "mainpage.h"
#include <QMessageBox>
Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_clicked()
{
    this->hide();
    withdrawl obj;
    obj.setModal(true);
    obj.exec();
}


void Options::on_pushButton_2_clicked()
{
    this->hide();
    deposit obj1;
    obj1.setModal(true);
    obj1.exec();

}


void Options::on_pushButton_3_clicked()
{
    this->hide();
    Fundstransfer obj;
    obj.setModal(true);
    obj.exec();
}


void Options::on_pushButton_7_clicked()
{
    MainPage obj;
    obj.connOpen();
    QSqlQuery qry;
    QString balance;
    qry.prepare("SELECT Balance FROM record Where Username='"+username+"'");
    qry.exec();
    qry.first();
    balance = qry.value(0).toString();
    QMessageBox::information(this,"Balance Check","Your balance is Rs."+balance);
    obj.connClose();
}



void Options::on_pushButton_4_clicked()
{
    this->hide();
    changepin obj;
    obj.setModal(true);
    obj.exec();
}


void Options::on_pushButton_5_clicked()
{
    this->hide();
    changepword obj;
    obj.setModal(true);
    obj.exec();
}


void Options::on_pushButton_8_clicked()
{
this ->hide();
    Accountstatement obj;
    obj.setModal(true);
    obj.exec();
}


void Options::on_pushButton_9_clicked()
{
    this->close();
}

