#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_ClickNew_triggered();

    void on_OnClickSave_triggered();

    void on_ClickSaveAs_triggered();
    
    void on_ClickOpen_triggered();

    void on_ClickExit_triggered();

    void on_ClickRevert_triggered();

    void on_ClickClip_triggered();

    void on_ClickCopy_triggered();

    void on_ClickPaste_triggered();

    void on_ClickClose_triggered();

private:
    void SaveOrNot();
    bool SaveFile(const QString& fileName);
    bool LoadFile(const QString& fileName);
private:
    Ui::MainWindow *ui;
    bool bSaved;            //当前文件是否已保存
    QString mCurrentPath;
};
#endif // MAINWINDOW_H
