#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include<QMessageBox>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),bSaved(false)
{
    ui->setupUi(this);
    mCurrentPath = tr("未命名.txt");
    setWindowTitle(mCurrentPath);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::SaveFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1 \n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);                 //创建字符流，指向文件
    out<<ui->textEdit->toPlainText();                       //将文本编辑器里的内容以纯文本输出到流
    bSaved = true;
    mCurrentPath = QFileInfo(fileName).canonicalFilePath();             //文件标准路径
    setWindowTitle(mCurrentPath);
    return true;
}
bool MainWindow::LoadFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("读取文件"),tr("无法读取文件 %1 \n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    mCurrentPath = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(mCurrentPath);
    return true;
}
void MainWindow::on_ClickNew_triggered()
{
    SaveOrNot();
    bSaved = false;
    mCurrentPath = tr("未命名.txt");
    setWindowTitle(mCurrentPath);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
}

void MainWindow::SaveOrNot()
{
    //如果文件被修改过，弹出保存对话框
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(mCurrentPath + tr("尚未保存，是否保存？"));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if(box.exec() == QMessageBox::Yes)
        {
            on_OnClickSave_triggered();
        }
    }
}

void MainWindow::on_OnClickSave_triggered()
{
    if(bSaved)
    {
        SaveFile(mCurrentPath);
    }
    else
    {
        on_ClickSaveAs_triggered();
    }
}

void MainWindow::on_ClickSaveAs_triggered()
{
    //QFileDialog::getSaveFileName(this,("另存为"),mCurrentPath);
    QString fileName = QFileDialog::getSaveFileName(this,QString("另存为"),mCurrentPath);
    if(!fileName.isEmpty())
    {
        SaveFile(fileName);
    }
}

void MainWindow::on_ClickOpen_triggered()
{
    SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        LoadFile(fileName);
    }
    ui->textEdit->setVisible(true);
}

void MainWindow::on_ClickClose_triggered()
{
    SaveOrNot();
    ui->textEdit->setVisible(false);
    qApp->quit();
}
void MainWindow::on_ClickExit_triggered()
{
    SaveOrNot();
    ui->textEdit->setVisible(false);
    qApp->quit();
}

void MainWindow::on_ClickRevert_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_ClickClip_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_ClickCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_ClickPaste_triggered()
{
    ui->textEdit->paste();
}


