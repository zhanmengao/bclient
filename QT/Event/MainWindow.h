//
// Created by gaochong on 2020/5/15.
//

#ifndef XMM_MAINWINDOW_H
#define XMM_MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>

class MainWindow : public QMainWindow{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0 );
    virtual ~MainWindow();

private:

    QLineEdit *filename;

    int AddFileExeMode(QString sFilePath);
    int CateDesktopLink(QString optinStr);
    //int OpenDesktopFile(QString filename);
    //QByteArray AESDecode(QString Cipher_Text);
    //QString GetCorrectUnicode(const QByteArray &ba);

private slots:
    void codeButton2Clicked();
    void codeButtonClicked();
    void setAcceptDrops2();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    void SetFile(QString file_name);

    void SetFile(QString username, QString file_name);
};


#endif //XMM_MAINWINDOW_H
