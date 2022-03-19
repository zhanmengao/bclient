#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSplashScreen>
#include <QtWidgets/QLabel>
#include <QtGui/QMovie>
#include <QtCore/QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ICOPATH = "../resources/loading.gif";
    timer = new QTimer(this);
    timer->setInterval(5000);
    timer->setSingleShot(true);
    QObject::connect(timer,&QTimer::timeout, this, &MainWindow::OnTimeOut);
    qDebug() <<"loading: " << ICOPATH;

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout( mainLayout );
    this->setCentralWidget(  mainWidget );

    QLabel *logoLabel = new QLabel();
    QMovie *movie = new QMovie(ICOPATH);
    movie->setSpeed(100 );
    movie->setCacheMode( QMovie::CacheAll);
    logoLabel->setMovie(movie);
    movie->start();

    QHBoxLayout *logoLayout = new QHBoxLayout();
    logoLayout->addStretch();
    logoLayout->addWidget( logoLabel );
    logoLayout->addStretch();
    mainLayout->addLayout( logoLayout );
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::OnTimeOut()
{
    qDebug("LogoWindow OnTimeOut %d",timer->interval());
    this->hide();
}
void MainWindow::hideEvent(QHideEvent *event)
{
    timer->stop();
    QWidget::hideEvent(event);
}

void MainWindow::showEvent(QShowEvent *event)
{
    timer->start();
    qDebug("LogoWindow show %d begin",timer->interval());
    QWidget::showEvent(event);
}
