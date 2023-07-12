#include "changepword.h"
#include "ui_changepword.h"
#include "mainpage.h"
changepword::changepword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepword)
{
    ui->setupUi(this);
        ui->pushButton->setDisabled(true);

}
changepword::~changepword()
{
    delete ui;
}

void changepword::on_pushButton_clicked()
{
    QString current = ui->lineEdit->text();
    QString pword = ui->lineEdit_2->text();
    MainPage obj;
    obj.connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT Password FROM record where Username ='"+username+"'");
    qry.exec();
    qry.first();
    QString check = qry.value(0).toString();
    obj.connClose();
    if(current == check){
        obj.connOpen();
        QSqlQuery qry1;
        qry1.prepare("UPDATE record set Password= '"+pword+"' WHERE Username ='"+username+"'");
        qry1.exec();
        obj.connClose();
        QMessageBox::information(this,"Success","Password changed sucessfully");
    }
    else{
        QMessageBox::critical(this,"Failed", "Incorrect Password");
    }
    this->hide();
    Options obj1;
    obj1.setModal(true);
    obj1.exec();
}


void changepword::on_pushButton_2_clicked()
{
    this->hide();
    Options obj1;
    obj1.setModal(true);
    obj1.exec();
}


void changepword::on_lineEdit_2_editingFinished()
{
    if(ui->lineEdit_2->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void changepword::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}

