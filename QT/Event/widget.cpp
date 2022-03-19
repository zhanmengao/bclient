#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QMouseEvent>
#include<QTimer>
#include<QMimeData>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    label = new QLabel("点击我",this);
    label->installEventFilter(this);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10000);
    setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}


bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == label)//指定某个QLabel
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = (QMouseEvent*)(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                QMessageBox::information(NULL,"点击","点击了我",
                                         QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}
void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
    //QWidget::dragEnterEvent(event);
}

void Widget::dropEvent(QDropEvent *event)
{

    QList<QUrl > urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
        return ;
    }

    QString dropEvent_filename = urls.first().toLocalFile();
    if( dropEvent_filename.isEmpty()){
        return ;
    }
    qDebug("%s",dropEvent_filename.toStdString().c_str());


    //QWidget::dropEvent(event);
}

void Widget::update()
{
    qDebug("Update Call");
}
