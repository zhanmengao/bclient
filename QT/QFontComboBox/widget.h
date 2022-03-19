#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QFont>
#include<QFontComboBox>
#include<QLabel>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void changedIndex(int idx);
    void changedFont(const QFont& rFont);
private:
    Ui::Widget *ui;

    QFontComboBox *pFontBox[5];
    QLabel *pLabel[5];
};
#endif // WIDGET_H
