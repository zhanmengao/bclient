#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    int yPos = 30;
    for(int i = 0;i<5;i++,yPos+=40)
    {
        pFontBox[i] = new QFontComboBox(this);
        pLabel[i] = new QLabel("I Love XinYi",this);
        pFontBox[i]->setGeometry(10,yPos,200,30);
        pLabel[i]->setGeometry(260,yPos,200,30);
        connect(pFontBox[i],SIGNAL(currentIndexChanged(int)),this,SLOT(changedIndex(int)));
        connect(pFontBox[i],SIGNAL(currentFontChanged(QFont)),this,SLOT(changedFont(const QFont&)));
    }
    pFontBox[0]->setFontFilters(QFontComboBox::AllFonts);
    pFontBox[1]->setFontFilters(QFontComboBox::ScalableFonts);
    pFontBox[2]->setFontFilters(QFontComboBox::NonScalableFonts);
    pFontBox[3]->setFontFilters(QFontComboBox::MonospacedFonts);
    pFontBox[4]->setFontFilters(QFontComboBox::ProportionalFonts);

}
void Widget::changedIndex(int idx)
{
    qDebug("Font index : %d", idx);
}
void Widget::changedFont(const QFont& rFont)
{
    for(int i = 0;i<5;i++)
    {
        pLabel[i]->setFont(pFontBox[i]->currentFont());
    }
}
Widget::~Widget()
{
    delete ui;
}

