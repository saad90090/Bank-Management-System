#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include "options.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainPage; }
QT_END_NAMESPACE

class MainPage : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
{
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Saad/Desktop/Database/customer.db");
        if(!mydb.open()){
            qDebug() << "NOT OPEN";
            return false;
        }
        else{
            qDebug() << "OPEN";
            return true;
        }
}
public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_uname_login_editingFinished();

    void on_pword_login_editingFinished();

    void on_name_reg_editingFinished();

    void on_uname_reg_editingFinished();

    void on_pword_reg_editingFinished();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pin_reg_editingFinished();

private:
    Ui::MainPage *ui;

};
#endif // MAINPAGE_H
