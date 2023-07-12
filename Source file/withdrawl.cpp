#include "withdrawl.h"
#include "ui_withdrawl.h"
#include "options.h"
#include <QTime>
#include "mainpage.h"
withdrawl::withdrawl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdrawl)
{
    ui->setupUi(this);
    ui->pushButton->setDisabled(true);
}

withdrawl::~withdrawl()
{
    delete ui;
}

void withdrawl::on_pushButton_clicked()
{
    QString current = ui->pin->text();
    MainPage obj;
    obj.connOpen();
    QSqlQuery qrya;
    qrya.prepare("SELECT PIN FROM record where Username = '"+username+"'");
    qrya.exec();
    qrya.first();
    QString check = qrya.value(0).toString();
    obj.connClose();
    if(current == check){
    int a = ui->lineEdit->text().toInt();
    int b;
    QString balance;
    obj.connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM record WHERE Username='"+ username+"'" );
    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            qry.first();
            balance = qry.value(6).toString();
            obj.connClose();
        }
    }
    if(balance.toInt()>=a){
        b = balance.toInt()-a;
        QString str;
        QString time = QDateTime::currentDateTime().toString();
        str.setNum(b);
        obj.connOpen();
        QSqlQuery query;
        query.prepare("UPDATE record set Balance='"+str+"' WHERE Username='"+ username+"'");
        if(query.exec()){
            QMessageBox::information(this,"Success","Funds withdrawn successfully");
        }
        else{
            QMessageBox::critical(this,"Failed","Failed");
        }
        obj.connClose();
        obj.connOpen();
        QSqlQuery qr1;
        qr1.prepare("INSERT INTO statement(Username,Amount,Mode,Date,Status) VALUES(:Username,:Amount,:Mode,:Date,:Status)");
        qr1.bindValue(":Username",username);
        qr1.bindValue(":Amount",a);
        qr1.bindValue(":Mode","Cash Withdrawl");
        qr1.bindValue(":Status","Debited");
        qr1.bindValue(":Date",time);
        qr1.exec();
        obj.connClose();
    }
    else{
        QMessageBox::critical(this,"Failed","Insufficient Funds");
    }
    this->hide();
    Options obj1;
    obj1.setModal(true);
    obj1.exec();
    }
    else{
        QMessageBox::critical(this,"Failed","Incorrect PIN");
    }

}



void withdrawl::on_pushButton_2_clicked()
{
    this->hide();
    Options obj;
    obj.setModal(true);
    obj.exec();
}


void withdrawl::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void withdrawl::on_pin_editingFinished()
{
    if(ui->pin->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}

