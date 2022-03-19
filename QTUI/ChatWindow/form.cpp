#include "form.h"
#include "ui_form.h"
#include<QByteArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    i=0;
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    QMovie *movie = new QMovie(":/red69-2.gif");
    ui->label->setMovie(movie);
    ui->label_2->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    movie->start();
    ui->label_4->setStyleSheet("border-radius:15px;background-color:green;border-image:url(':/11.jpg')");
    ui->label_5->setOpenExternalLinks(true);

    ui->label_5->installEventFilter(this);
    animation=new QPropertyAnimation(ui->label_4, "geometry");
    animation->setDuration(400);
    animation->setStartValue(QRect(30, 170, 85, 85));
    animation->setEndValue(QRect(150, 170, 85, 85));

    QString qss;
    QFile qssFile(":/myqss/login.qss");
    qssFile.open(QFile::ReadOnly);
    qDebug()<<"sdfasd";
    if(qssFile.isOpen())
    {

        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
        qDebug()<<"成功引入qss";
    }

}

Form::~Form()
{
    delete ui;
}
void Form::mousePressEvent(QMouseEvent *event)
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

void Form::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
    //  qDebug()<<"mouse_press="<<event->globalPos();
    if(mouse_press)
    {
        i++;
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();
        qDebug()<<"移动"<<i;
        //移动主窗体位置
        this->move(move_pos - move_point);
    }
}

bool Form::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label_3)
    {
        close();
    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_2){
        showMinimized();
        qDebug()<<"最小化";

    }
    else if(e->type()==QEvent::MouseButtonPress&&object==ui->label_5){
        QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
        mouse_press=false;

    }
    return false;
}


void Form::on_pushButton_clicked()
{
    qDebug()<<ui->lineEdit->text();
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()=="")
    {
        qDebug()<<"内容为空";
        ui->label_6->setText("账号密码不能为空");
    }
    else
    {
        ui->label_6->hide();
        ui->pushButton->hide();
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->label_5->hide();
        animation->start();
        Talk* t=new Talk();

        setVisible(false);
        t->show();
    }
}

void Form::on_lineEdit_2_returnPressed()
{
    qDebug()<<"输入结束66";
}

void Form::showEvent(QShowEvent *event)
{
    mouse_press=false;
}

void Form::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug()<<"正在编辑"+arg1;
    if(ui->label_6->text()!="")
    {
        qDebug()<<"进入了这个函数";
        ui->label_6->setText("");
    }

}

