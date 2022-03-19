#include"widget.h"

void Widget::OnClickDir()
{
    //getExistingDirectory:选择文件夹
    QString directory = QFileDialog::getExistingDirectory(this,tr("getExistingDirectory"),"/home",op);
    qDebug("getExistingDirectory %s",directory.toStdString().c_str());
}
void Widget::OnClickOpenFile()
{
    QString selectFilter;
    //getOpenFileName选择文件
    QString fileName = QFileDialog::getOpenFileName(this,tr("getOpenFileName"),"/",
                                                  tr("All Files (*);;Text File (*.txt)"),&selectFilter,op);
    qDebug("getOpenFileName %s",fileName.toStdString().c_str());
}
void Widget::OnClickOpenFiles()
{
    QString selectedFilter;
    //getOpenFileNames选择多个文件
    QStringList fileNameList = QFileDialog::getOpenFileNames(this,tr("getOpenFileNames"),"/",
                                                  tr("All Files (*);;Text File (*.txt)"),&selectedFilter,op);
    for(auto it = fileNameList.begin();it!=fileNameList.end();it++)
    {
        qDebug("getOpenFileNames %s",it->toStdString().c_str());
    }
}
void Widget::OnClickSaveFile()
{
    QString saveFilter;
    QString saveFileName = QFileDialog::getSaveFileName(this,tr("getSaveFileName"),"/",
                                                         tr("All Files (*);;Text File (*.txt)"),&saveFilter,op);
    qDebug("getSaveFileName %s",saveFileName.toStdString().c_str());
}
