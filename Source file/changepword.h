#ifndef CHANGEPWORD_H
#define CHANGEPWORD_H

#include <QDialog>

namespace Ui {
class changepword;
}

class changepword : public QDialog
{
    Q_OBJECT

public:
    explicit changepword(QWidget *parent = nullptr);
    ~changepword();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

private:
    Ui::changepword *ui;
    QString current;
    void setCurrent(QString a){
        current=a;
    }
};

#endif // CHANGEPWORD_H
