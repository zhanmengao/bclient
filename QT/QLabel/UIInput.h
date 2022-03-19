#ifndef UIINPUT_H
#define UIINPUT_H


#include <QWidget>
#include<QLabel>
#include<QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    InputWidget(QWidget *parent = nullptr):QWidget(parent)
    {
    }
    ~InputWidget()
    {
    }
    void InitLineEdit();
private slots:
    void textChanged(const QString& str);

private:
    QLineEdit *mInput;
    QLabel *mLabel;
    QString mStr;

   QLineEdit *mEdit[4];
};

#endif // UIINPUT_H
