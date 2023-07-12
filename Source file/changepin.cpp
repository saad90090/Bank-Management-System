#include "changepin.h"
#include "ui_changepin.h"
#include "mainpage.h"
changepin::changepin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepin)
{
    ui->setupUi(this);
        ui->pushButton->setDisabled(true);

}

changepin::~changepin()
{
    delete ui;
}

void changepin::on_pushButton_clicked()
{
      QString current = ui->lineEdit->text();
      MainPage obj;
      obj.connOpen();
      QSqlQuery qry;
      qry.prepare("SELECT PIN FROM record where Username = '"+username+"'");
      qry.exec();
      qry.first();
      QString check = qry.value(0).toString();
      obj.connClose();
      if(current == check){
          QString newpin = ui->lineEdit_2->text();
          obj.connOpen();
          QSqlQuery qry1;
          qry1.prepare("UPDATE record set PIN = '"+newpin+"' WHERE Username ='"+username+"'");
          qry1.exec();
          obj.connClose();
          QMessageBox::information(this,"Success","PIN changed sucessfully");
      }
      else{
          QMessageBox::critical(this,"Failed","Authentication Failed:Wrong PIN entered");
      }
      this->hide();
      Options obj1;
      obj1.setModal(true);
      obj1.exec();
}


void changepin::on_pushButton_2_clicked()
{
    this->hide();
    Options obj1;
    obj1.setModal(true);
    obj1.exec();
}


void changepin::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void changepin::on_lineEdit_2_editingFinished()
{
    if(ui->lineEdit_2->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}

