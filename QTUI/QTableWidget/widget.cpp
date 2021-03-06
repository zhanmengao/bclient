#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QDebug>
#include"../../../System/SystemInfo/OSInfo/NetInfo.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(255);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
    ui->lineEdit->setText("192.168.50");
}

Widget::~Widget()
{
    delete ui;
}

int useRow = 0;

void Widget::lookUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError)
    {
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }

    if(host.addresses()[0].toString() == host.hostName())
        return;

    QString ip = host.addresses()[0].toString();
    QTableWidgetItem *ipItem = new QTableWidgetItem;
    ipItem->setText(ip);
    QTableWidgetItem *hostItem = new QTableWidgetItem;
    hostItem->setText(host.hostName());
    //arp
    auto mac = GetMac(ip.toUtf8().data());
    QTableWidgetItem *macItem = new QTableWidgetItem;
    macItem->setText(mac.c_str());

    if(ipItem->text() != hostItem->text())
    {
        ipItem->setTextColor(QColor(Qt::red));
        hostItem->setTextColor(QColor(Qt::red));
    }
    ui->tableWidget->setItem(useRow, 0, ipItem);
    ui->tableWidget->setItem(useRow, 1, hostItem);
    ui->tableWidget->setItem(useRow, 2, macItem);
    useRow++;
}

void Widget::btnClicked()
{
    ui->tableWidget->clear();
    QString ip = ui->lineEdit->text();
    for(int i = 1 ; i < 256; i++)
    {
        QHostInfo::lookupHost(ip + QString(".%1").arg(i), this, SLOT(lookUp(QHostInfo)));
    }
}
