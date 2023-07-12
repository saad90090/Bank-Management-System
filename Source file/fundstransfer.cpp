#include "fundstransfer.h"
#include "ui_fundstransfer.h"
#include "mainpage.h"
Fundstransfer::Fundstransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fundstransfer)
{
    ui->setupUi(this);

        ui->pushButton->setDisabled(true);

}

Fundstransfer::~Fundstransfer()
{
    delete ui;
}

void Fundstransfer::on_pushButton_clicked()
{
    QString current = ui->lineEdit->text();
    MainPage obj;
    obj.connOpen();
    QSqlQuery qrya;
    qrya.prepare("SELECT PIN FROM record where Username = '"+username+"'");
    qrya.exec();
    qrya.first();
    QString check = qrya.value(0).toString();
    obj.connClose();
    if(current == check){
        int a = ui->amount->text().toInt();
        int b;
        QString accountnum = ui->accountnum->text();
        QString str;
        QString balance;
        QString time = QDateTime::currentDateTime().toString();
        obj.connOpen();
        QSqlQuery chk;
        chk.prepare("SELECT * FROM record WHERE Accountnum='"+accountnum+"'");
        chk.exec();
        chk.first();
        QString acheck = chk.value(0).toString();
        obj.connClose();
        if(accountnum==acheck){
            obj.connOpen();
            QSqlQuery qry1;
            qry1.prepare("SELECT * FROM record WHERE Username='"+username+"'" );
            if(qry1.exec()){
                int count=0;
                while(qry1.next()){
                    count++;
                }
                if(count==1){
                    qry1.first();
                    balance = qry1.value(6).toString();

                    obj.connClose();
                }

            }
            b = balance.toInt()-a;
            str.setNum(b);
            if(balance.toInt() >= a){
                obj.connOpen();
                QSqlQuery query1;
                query1.prepare("UPDATE record set Balance='"+str+"' WHERE Username='"+username+"'");
                if(query1.exec()){
                    QMessageBox::information(this,"Success","Funds transferred successfully");
                }
                obj.connClose();
                obj.connOpen();
                QSqlQuery qry;
                qry.prepare("SELECT * FROM record WHERE Accountnum='"+accountnum+"'" );
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
                b = balance.toInt()+a;
                str.setNum(b);
                obj.connOpen();
                QSqlQuery query;
                query.prepare("UPDATE record set Balance='"+str+"' WHERE Accountnum='"+accountnum+"'");
                query.exec();
                obj.connClose();
                obj.connOpen();
                QSqlQuery qr1;
                qr1.prepare("INSERT INTO statement(Username,Amount,Mode,Date,Status,Receiver) VALUES(:Username,:Amount,:Mode,:Date,:Status,:Receiver)");
                qr1.bindValue(":Username",username);
                qr1.bindValue(":Amount",a);
                qr1.bindValue(":Mode","Funds Transfer");
                qr1.bindValue(":Status","Debited");
                qr1.bindValue(":Date",time);
                qr1.bindValue(":Receiver",accountnum);
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
            QMessageBox::critical(this,"Invalid","Account does not exist");
        }

    }
    else{
        QMessageBox::critical(this,"Invalid","Incorrect PIN");
    }
}


void Fundstransfer::on_pushButton_2_clicked()
{
    this->hide();
    Options obj;
    obj.setModal(true);
    obj.exec();
}


void Fundstransfer::on_accountnum_editingFinished()
{
    if(ui->accountnum->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void Fundstransfer::on_amount_editingFinished()
{
    if(ui->amount->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void Fundstransfer::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}

