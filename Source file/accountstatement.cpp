#include "accountstatement.h"
#include "ui_accountstatement.h"
#include "mainpage.h"
Accountstatement::Accountstatement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Accountstatement)
{
    ui->setupUi(this);
    MainPage obj;
    QSqlQueryModel *modal = new QSqlQueryModel();
    obj.connOpen();
    QSqlQuery*qry = new QSqlQuery(obj.mydb);
    qry->prepare("SELECT * FROM statement WHERE Username='"+username+"' ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    obj.connClose();
}

Accountstatement::~Accountstatement()
{
    delete ui;
}

void Accountstatement::on_pushButton_clicked()
{
    this->hide();
    Options obj1;
    obj1.setModal(true);
    obj1.exec();
}

