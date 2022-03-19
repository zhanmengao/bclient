#include"DetailWidget.h"
#include<string>
#include"widget.h"

FileDetailWidget::FileDetailWidget(QWidget* parent,unsigned int yPos):QWidget(parent)
{
    this->setGeometry(0,yPos,800,600);
    //init menu
    mMenuWidget = new QWidget(this);
    mMenuWidget->setGeometry(0,0,800,130);
    mPathLab = new QLabel(mMenuWidget);
    mPathLab->setGeometry(20,50,400,100);
    mPathLab->setAlignment(Qt::AlignLeft| Qt::AlignTop);
    mNameLab = new QLabel(mMenuWidget);
    mNameLab->setGeometry(40,100,400,100);
    mNameLab->setText("Name");
    mNameLab->setAlignment(Qt::AlignLeft| Qt::AlignTop);
    mSizeLab = new QLabel(mMenuWidget);
    mSizeLab->setGeometry(500,100,100,100);
    mSizeLab->setText("Size");
    mSizeLab->setAlignment(Qt::AlignLeft| Qt::AlignTop);

    mMenu = new QToolBar(this);

    mAct[0] = new QAction( "Back", this);
    mAct[1] = new QAction("AddFolder", this);
    mAct[2] = new QAction("Delete", this);
    mAct[3] = new QAction( "Rename", this);
    mAct[4] = new QAction("Down", this);
    mAct[5] = new QAction("Up", this);
    mAct[6] = new QAction("Close", this);
    mMenu->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    for(int i = 0 ; i < sizeof(mAct)/sizeof(mAct[0]) ; i++)
    {
        mMenu->addAction(mAct[i]);
    }
    connect(mAct[0], &QAction::triggered, this, &FileDetailWidget::OnClickBack);
    connect(mAct[1], &QAction::triggered, this, &FileDetailWidget::OnClickCreateFolder);
    connect(mAct[2], &QAction::triggered, this, &FileDetailWidget::OnClickDelete);
    connect(mAct[3], &QAction::triggered, this, &FileDetailWidget::OnClickRename);
    connect(mAct[4], &QAction::triggered, this, &FileDetailWidget::OnClickDown);
    connect(mAct[5], &QAction::triggered, this, &FileDetailWidget::OnClickUp);
    connect(mAct[6], &QAction::triggered, this, &FileDetailWidget::OnClickClose);

    mFileListWidget = new QWidget(this);
    mFileListWidget->setGeometry(0,130,600,600);
    btnFrame = new QFocusFrame(mFileListWidget);
    btnFrame->setAutoFillBackground(true);
    btnFrame->setWidget(nullptr);
    btnFrame->setGeometry(0,0,0,0);
	mFileListScroll = new QScrollArea(this);
	mFileListScroll->setWidget(mFileListWidget);
	mFileListScroll->setGeometry(0, 130, 650, 400);
	mFileListScroll->setBackgroundRole(QPalette::Light);
}
FileDetailWidget::~FileDetailWidget()
{
}

void FileDetailWidget::InitDetailList()
{
    mPathLab->setText("C:/Windows/System32/");
    for(auto it = mDetailVec.begin();it!=mDetailVec.end();)
    {
        if(*it!=nullptr)
        {
            delete *it;
        }
        it = mDetailVec.erase(it);
    }
    for(int i = 0;i<30;i++)
    {
        FileDetailItem *logic = new FileDetailItem(mFileListWidget,10,30*i+20);
        logic->Init();
        mDetailVec.push_back(logic);
    }
	mFileListWidget->resize(600, mDetailVec.size() * 30 + 30);
	this->show();
}
bool FileDetailWidget::IsSame() const
{
    return false;
}
void FileDetailWidget::OnFileChoose(FileDetailItem *item)
{
    mCurChooseFile = item;
    btnFrame->setWidget(item);
    qDebug("OnFileChoose");
}
void FileDetailWidget::OnClickBack()
{
    qDebug("Back click.");
}
void FileDetailWidget::OnClickCreateFolder()
{
    qDebug("OnClickCreateFolder click.");
}

void FileDetailWidget::OnClickDelete()
{
    qDebug("OnClickDelete click.");
}

void FileDetailWidget::OnClickRename()
{
	if (mCurChooseFile == nullptr)
	{
		return;
	}
	mCurChooseFile->OnRenameBegin();
    qDebug("OnClickRename click.");
}

void FileDetailWidget::OnClickDown()
{
    qDebug("OnClickDown click.");
}

void FileDetailWidget::OnClickUp()
{
    qDebug("OnClickUp click.");
}
void FileDetailWidget::OnClickClose()
{
    if(Widget::Instance()!=nullptr)
    {
        Widget::Instance()->OnClickCloseFile();
    }
}
