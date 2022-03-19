#include"DetailItem.h"
#include<QMouseEvent>
#include"widget.h"
FileDetailItem::FileDetailItem(QWidget* parent, unsigned int xPos, unsigned int yPos) :QWidget(parent)
{
	this->setGeometry(xPos, yPos, 800, 30);
	mNameLab = new QLabel(this);
	mNameLab->installEventFilter(this);
	mSizeLab = new QLabel(this);
	mSizeLab->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mNameLab->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mNameLab->setGeometry(40, 0, 400, 30);
	mSizeLab->setGeometry(500, 0, 100, 30);
	mRenameEdit = nullptr;
}
void FileDetailItem::Init()
{
	mNameLab->setText("QAQ");
	mSizeLab->setNum(99);
}
bool FileDetailItem::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
	{
		QMouseEvent *mouseEvent = (QMouseEvent*)(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			if (obj == mNameLab || obj == mSizeLab)//指定某个QLabel
			{
				OnChoose();
				return true;
			}
		}
	}
	//双击进入
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent *mouseEvent = (QMouseEvent*)(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			if (obj == mNameLab || obj == mSizeLab)
			{
				return true;
			}
		}
	}
	return QWidget::eventFilter(obj, event);
}
void FileDetailItem::OnChoose()
{
	if (Widget::Instance() != nullptr)
	{
		Widget::Instance()->OnChooseFile(this);
	}
}
void FileDetailItem::OnEnter()
{

}
void FileDetailItem::OnRenameBegin()
{
	if (mRenameEdit == nullptr)
	{
		mRenameEdit = new QLineEdit(this);
		mRenameEdit->setGeometry(40, 0, 400, 30);
		mRenameEdit->setText(mNameLab->text());
		connect(mRenameEdit, &QLineEdit::returnPressed, this,&FileDetailItem::OnRenameEnd);
	}
	mRenameEdit->show();
	mNameLab->hide();
}
void FileDetailItem::OnRenameEnd()
{
	mRenameEdit->hide();
	mNameLab->setText(mRenameEdit->text());
	mNameLab->show();
}
