#include"Item.h"
#include"../QSTPicture/IconUtils.h"


Item::Item(const QString& icon,QWidget *parent):QWidget(parent)
{
    lab = new QLabel(this);
    lab->setPixmap(IconUtils::GetIcon(icon,30,30));
}

Item::~Item()
{

}
