#include "mainpage.h"
#include "ui_mainpage.h"
#include <QIntValidator>
QString username;
MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);

    ui->pushButton->setDisabled(true);


}


MainPage::~MainPage()
{
    delete ui;
}


void MainPage::on_pushButton_clicked()
{
    if(ui->uname_login->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }
    QString password;
    username = ui->uname_login->text();
    password = ui->pword_login->text();
    connOpen();
    if(!mydb.isOpen()){
        qDebug() << "Failed to open";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM record WHERE Username='"+ username+"' AND Password='"+password+"'" );
    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            QMessageBox::information(this,"Success","Login Success");
            connClose();
            this->hide();
            Options options;
            options.setModal(true);
            options.exec();
        }
        else{
            QMessageBox::critical(this,"Not Success","Login Failed");
        }
    }

}


void MainPage::on_pushButton_2_clicked()
{
    if(ui->name_reg->text().isEmpty() || ui->pin_reg->text().isEmpty() || ui->uname_reg->text().isEmpty()
             || ui->pword_reg->text().isEmpty() || ui->dateEdit->text().isEmpty()){
        QMessageBox::critical(this,"Error","Fill all the fields");

    }
    else{
    QString Name,Username,Password,Gender,DOB,PIN;
    if(ui->male->isChecked()){
        Gender = "Male";
    }
    if(ui->female->isChecked()){
        Gender = "Female";
    }
    Name= ui->name_reg->text();
    Username = ui->uname_reg->text();
    Password = ui->pword_reg->text();
    DOB=ui->dateEdit->text();
    PIN=ui->pin_reg->text();
    connOpen();
    if(!mydb.isOpen()){
        qDebug() << "Failed to open";
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO record(Name,Username,Password,Gender,DOB,PIN) VALUES('"+Name+"','"+Username+"','"+Password+"','"+Gender+"','"+DOB+"','"+PIN+"')");
    if(query.exec()){
        QMessageBox::information(this,"Success","User Registered Successfully");
        connClose();
        ui->uname_reg->QLineEdit::clear();
        ui->name_reg->QLineEdit::clear();
        ui->pword_reg->QLineEdit::clear();
        ui->pin_reg->QLineEdit::clear();
    }
    else{
        QMessageBox::critical(this,"Failed","Username already taken");
    }
    }

}


void MainPage::on_uname_login_editingFinished()
{
    if(ui->uname_login->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void MainPage::on_pword_login_editingFinished()
{
    if(ui->pword_login->text().isEmpty()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}


void MainPage::on_name_reg_editingFinished()
{

}


void MainPage::on_uname_reg_editingFinished()
{

}


void MainPage::on_pword_reg_editingFinished()
{


}

void MainPage::on_dateEdit_dateChanged(const QDate &date)
{

}

void MainPage::on_pin_reg_editingFinished()
{

}

