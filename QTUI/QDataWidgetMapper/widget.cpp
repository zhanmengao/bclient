#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupModel();

    nameLabel = new QLabel(tr("Na&me:"));
    nameEdit = new QLineEdit();
    addressLabel = new QLabel(tr("&Address:"));
    addressEdit = new QTextEdit();
    typeLabel = new QLabel(tr("&Type:"));
    typeComboBox = new QComboBox();
    nextButton = new QPushButton(tr("&Next"));
    previousButton = new QPushButton(tr("&Previous"));

    nameLabel->setBuddy(nameEdit);
    addressLabel->setBuddy(addressEdit);
    typeLabel->setBuddy(typeComboBox);
    typeComboBox->setModel(typeModel);

    //mapper与控件之间映射数据，实现改变模型数据的当前索引时，也改变控件的数据
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit, 0);
    mapper->addMapping(addressEdit, 1);
    mapper->addMapping(typeComboBox, 2, "currentIndex");
    connect(previousButton, SIGNAL(clicked()),
            mapper, SLOT(toPrevious()));      //上一个
    connect(nextButton, SIGNAL(clicked()),
            mapper, SLOT(toNext()));        //下一个
    connect(mapper, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateButtons(int)));

    //布局
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(nameLabel, 0, 0, 1, 1);
    layout->addWidget(nameEdit, 0, 1, 1, 1);
    layout->addWidget(previousButton, 0, 2, 1, 1);
    layout->addWidget(addressLabel, 1, 0, 1, 1);
    layout->addWidget(addressEdit, 1, 1, 2, 1);
    layout->addWidget(nextButton, 1, 2, 1, 1);
    layout->addWidget(typeLabel, 3, 0, 1, 1);
    layout->addWidget(typeComboBox, 3, 1, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Delegate Widget Mapper"));
    mapper->toFirst();
}

void Widget::setupModel()
{
    //QComboBox
    QStringList items;
    items << tr("Home") << tr("Work") << tr("Other");
    typeModel = new QStringListModel(items, this);

    //name
    model = new QStandardItemModel(5, 3, this);
    QStringList names;
    names << "Alice" << "Bob" << "Carol" << "Donald" << "Emma";

    //addr
    QStringList addresses;
    addresses << "<qt>123 Main Street<br/>Market Town</qt>"
           << "<qt>PO Box 32<br/>Mail Handling Service"
              "<br/>Service City</qt>"
           << "<qt>The Lighthouse<br/>Remote Island</qt>"
           << "<qt>47338 Park Avenue<br/>Big City</qt>"
           << "<qt>Research Station<br/>Base Camp<br/>Big Mountain</qt>";

    //把数据写进model
    QStringList types;
    types << "0" << "1" << "2" << "0" << "2";
    for (int row = 0; row < 5; ++row)
    {
        QStandardItem *item = new QStandardItem(names[row]);
        model->setItem(row, 0, item);     //第一行,名称
        item = new QStandardItem(addresses[row]);
        model->setItem(row, 1, item);     //第二行，地址
        item = new QStandardItem(types[row]);
        model->setItem(row, 2, item);      //第三行，类型
    }
}

void Widget::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);                    //previous按钮是否可点
    nextButton->setEnabled(row < model->rowCount() - 1);      //next是否可点
}


Widget::~Widget()
{
}
