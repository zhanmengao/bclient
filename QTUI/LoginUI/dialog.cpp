#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginBtn_clicked()
{
    if(ui->userEdit->text().trimmed() == tr("qt") && ui->pwdEdit->text() == tr("123456"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("User name or password error"),QMessageBox::Yes);
        ui->pwdEdit->setFocus();
        ui->pwdEdit->clear();
    }
}
