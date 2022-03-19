#ifndef DETAILWIDGET_H
#define DETAILWIDGET_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<vector>
#include"DetailItem.h"
#include <QToolBar>
#include <QAction>
#include<QScrollArea>

class FileDetailWidget:public QWidget
{
private:
    //Menu
    QWidget *mMenuWidget;
    QToolBar *mMenu;
    QAction* mAct[7];
    QLabel *mPathLab;
    QLabel *mNameLab;
    QLabel *mSizeLab;

    QWidget *mFileListWidget;
	QScrollArea *mFileListScroll;
    std::vector<FileDetailItem*> mDetailVec;
    QFocusFrame *btnFrame;
    FileDetailItem* mCurChooseFile;
public:
    FileDetailWidget(QWidget* parent = nullptr,unsigned int yPos = 0);
    ~FileDetailWidget();
private slots:
    void OnClickBack();
    void OnClickCreateFolder();
    void OnClickDelete();
    void OnClickRename();
    void OnClickDown();
    void OnClickUp();
    void OnClickClose();
public:
    void InitDetailList();
    bool IsSame() const;
    void OnFileChoose(FileDetailItem *item);
};

#endif // DETAILWIDGET_H
