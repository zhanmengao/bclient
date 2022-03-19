#include"widget.h"
#include<QColorDialog>
void Widget::OnClickColor()
{
    QColor color = QColorDialog::getColor
            (Qt::yellow,this,"OnClickColor",QColorDialog::DontUseNativeDialog);
    if(color.isValid())
    {
        qDebug(("Select:" + color.name()).toStdString().c_str());
        pLab2->setText(color.name());
        pLab2->setPalette(QPalette(color));
        pLab2->setAutoFillBackground(true);
    }
}
