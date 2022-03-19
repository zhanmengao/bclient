//
// Created by gaochong on 2020/5/15.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QLabel>
#include <QDebug>
#include <string>
#include <QtCore/QJsonObject>
#include <QJsonDocument>
#include <QtCore/QProcessEnvironment>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <sys/stat.h>


#include <QMimeData>
#include <QFileDialog>
#include <QSettings>
#include <sstream>
#include <QtCore/QCryptographicHash>
#include <QTextCodec>
#include <QMessageBox>

#include "MainWindow.h"
#include "qaesencryption.h"

#include <QProcess>

using namespace std;

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){

    this->setWindowTitle("TEST");
    this->setFixedWidth(620);
    //this->setFixedHeight(580);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

    filename = new QLineEdit("");

    QLabel *filenameLabel = new QLabel("filename：");

    QPushButton *codeButton = new QPushButton("修复文件");
    QPushButton *codeButton2 = new QPushButton("选择文件");

    QHBoxLayout *layout1 = new QHBoxLayout();

    layout1->addWidget(filenameLabel);
    layout1->addWidget(filename);

    mainLayout->addLayout(layout1);

    mainLayout->addWidget(codeButton2);
    mainLayout->addWidget(codeButton);

    connect(codeButton, &QPushButton::clicked, this, &MainWindow::codeButtonClicked);
    connect(codeButton2, &QPushButton::clicked, this, &MainWindow::codeButton2Clicked);

    setAcceptDrops2();
}

MainWindow::~MainWindow() {

}

void MainWindow::setAcceptDrops2(){

    this->setAcceptDrops( true );

    filename->setAcceptDrops( false );

}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {

    if(event->mimeData()->hasFormat("text/uri-list")){
        event->acceptProposedAction();
    }
    //QWidget::dragEnterEvent(event);
}

void MainWindow::dropEvent(QDropEvent *event) {

    QList<QUrl > urls = event->mimeData()->urls();
    if(urls.isEmpty()){
        return ;
    }

    QString dropEvent_filename = urls.first().toLocalFile();
    if( dropEvent_filename.isEmpty()){
        return ;
    }
    qDebug() << dropEvent_filename;

    filename->setText( dropEvent_filename );

    //QWidget::dropEvent(event);
}

void MainWindow::codeButton2Clicked(){

    QString file_name = QFileDialog::getOpenFileName(this,
                                                     "Open *.* File",
                                                     "~/Desktop",
                                                     "*.*",
                                                     0);
    if (!file_name.isNull()){

        filename->setText( file_name );

    }else{
        //...
    }

}

void MainWindow::codeButtonClicked() {

    QString file_name = filename->text();

    QString username = QProcessEnvironment::systemEnvironment().value("USERNAME");

    SetFile( username ,file_name  );
}

void MainWindow::SetFile(  QString username , QString file_name  ) {


    QProcess *_process  = new QProcess(this);


    QString cmd;

    QString processCMD = QString(
            "%1 chown %2 %3")
            .arg("pkexec")
            .arg( username )
            .arg( file_name );

    qDebug() << processCMD;

    _process->start(processCMD);
}


