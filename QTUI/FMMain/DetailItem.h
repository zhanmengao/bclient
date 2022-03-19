#ifndef FILEDETAILITEM_H
#define FILEDETAILITEM_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QFocusFrame>
#include<QLineEdit>
class FileDetailItem:public QWidget
{
public:
    FileDetailItem(QWidget* parent,unsigned int xPos,unsigned int yPos);
private:
    QLabel *mNameLab;
    QLabel *mSizeLab;
	QLineEdit *mRenameEdit;
public:
    void Init();
private:
    bool eventFilter(QObject *obj, QEvent *event);
    void OnChoose();
	void OnEnter();
public:
	void OnRenameBegin();
private slots:
	void OnRenameEnd();
};

#endif // FILEDETAILITEM_H
