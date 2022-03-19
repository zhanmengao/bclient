#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->label_4->installEventFilter(this);
    ui->label_5->installEventFilter(this);

    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->pushButton_2->setVisible(false);

}

Search::~Search()
{
    delete ui;
}

void Search::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
     {
         this->setMouseTracking(true);
          mouse_press = true;
          //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
          move_point = event->pos();
          qDebug()<<"移动1";
          qDebug()<<event->source();
     }

}

void Search::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
        mouse_press = false;

}

void Search::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
  //  qDebug()<<"mouse_press="<<event->globalPos();
        if(mouse_press)
        {

            //鼠标相对于屏幕的位置
            QPoint move_pos = event->globalPos();
           //移动主窗体位置
           this->move(move_pos - move_point);
        }
}

bool Search::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label_3)
    {
         //this->close();
         //e->ignore();
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_2){
        showMinimized();
        qDebug()<<"最小化";
        qDebug()<<mouse_press;

    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_4){

        ui->label_4->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
        ui->label_5->setStyleSheet("color:white");
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_5){

        ui->label_5->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
        ui->label_4->setStyleSheet("color:white");
    }

    return false;
}

void Search::showEvent(QShowEvent *event)
{
     qDebug()<<"出现了";
     mouse_press=false;
     qDebug()<<mouse_press;
}


void Search::on_pushButton_2_clicked()
{

}
void Search::doSearch(QString message)
{
    ui->lineEdit->setText(message);
}

void Search::on_pushButton_clicked()
{
}
