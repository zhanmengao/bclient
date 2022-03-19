#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include <QWidget>
#include<QDial>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class DialWidget : public QWidget
{
    Q_OBJECT

public:
    DialWidget(QWidget *parent = nullptr);
    ~DialWidget();
    void InitDial();
private slots:
    void OnVolumeChanged();
private:
    QDial *mDial[3];
};
#endif // DIALWIDGET_H
