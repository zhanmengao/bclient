#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    listWidget = new QListWidget(this);
    new QListWidgetItem(tr("Oak"), listWidget);
    new QListWidgetItem(tr("Fir"), listWidget);
    new QListWidgetItem(tr("Pine"), listWidget);


    QLabel *lbl = new QLabel(tr("select text:"));
    edt = new QLineEdit;

    QVBoxLayout *leftLayout = new QVBoxLayout;

    leftLayout->addWidget(listWidget);
    leftLayout->addWidget(lbl);
    leftLayout->addWidget(edt);

    //
    edt_add = new QLineEdit;
    QPushButton *add_btn = new QPushButton(tr("Add"));
    QPushButton *del_btn = new QPushButton(tr("Del"));
    QPushButton *quit_btn = new QPushButton(tr("Quit"));

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(edt_add);
    rightLayout->addWidget(add_btn);
    rightLayout->addWidget(del_btn);
    rightLayout->addStretch();
    rightLayout->addWidget(quit_btn);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);

    connect(listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(itemSelectionChanged ()));
    connect(add_btn, SIGNAL(clicked()), this, SLOT(on_add()));
    connect(del_btn, SIGNAL(clicked()), this, SLOT(on_del()));
    connect(quit_btn, SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::itemSelectionChanged()
{
    edt->setText(listWidget->currentItem()->text());
}

void MainWindow::on_add()
{
    listWidget->insertItem(listWidget->currentRow() + 1, edt_add->text());
}

void MainWindow::on_del()
{
    listWidget->takeItem(listWidget->currentRow());
}
