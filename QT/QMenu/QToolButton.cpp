#include "widget.h"

#include <QToolButton>
#include <QToolBar>
#include <QVBoxLayout>
#include <QIcon>

void Widget::InitToolButton()
{
    QToolBar *tool = new QToolBar(this);
    QVBoxLayout *layout = new QVBoxLayout;

    QToolButton *button = new QToolButton;
    button->setIcon(QIcon("../resources/browser.png"));
    button->setText("QToolButton");

    QToolButton *button1 = new QToolButton;
    button1->setIcon(QIcon("../resources/calendar.png"));

    QToolButton *button2 = new QToolButton;
    button2->setIcon(QIcon("../resources/chat.png"));

    tool->addWidget(button);
    tool->addWidget(button1);
    tool->addSeparator();
    tool->addWidget(button2);
    layout->addWidget(tool);

    this->setLayout(layout);
}

