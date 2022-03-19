#include "widget.h"

Widget::Widget(QMainWindow *parent)
    : QMainWindow(parent)
{
    resize(1024,768);
    pWebView = new QWebEngineView(this);
    pWebView->setUrl(QUrl("https://www.qq.com"));
    setCentralWidget(pWebView);
    pWebView->setAttribute(Qt::WA_DeleteOnClose);
    pWebView->resize(1024, 768);
    pWebView->showMinimized();
    pWebView->show();


    QWidget *mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);
    m_view = new MWebEngineView(mainWidget);
    QUrl url = QUrl("https://www.baidu.com/");
    m_view->load(url);
    m_view->addItemUrl(url);
    m_view->show();


    m_backBtn = new QPushButton(mainWidget);
    m_backBtn->resize(100,30);
    m_backBtn->move(0,0);
    m_backBtn->setText(tr("Back"));
    connect(m_backBtn, SIGNAL(clicked(bool)), this, SLOT(onBackBtnClicked()));
}

Widget::~Widget()
{
}

void Widget::resizeEvent(QResizeEvent *)
{
    m_view->resize(this->size());
}

void Widget::onBackBtnClicked()
{
    QList<QUrl> list = m_view->listUrl();
    QUrl currentUrl = m_view->url();
    int currentValue = -1;
    if(list.contains(currentUrl))
    {
        currentValue = list.indexOf(currentUrl);
        if(currentValue > 1)
        {
            m_view->load(list.at(currentValue - 1));
        }
        else
        {
            m_backBtn->setEnabled(false);
        }
    }
    else
    {
        m_view->addItemUrl(currentUrl);
        m_view->load(list.last());
    }
}
