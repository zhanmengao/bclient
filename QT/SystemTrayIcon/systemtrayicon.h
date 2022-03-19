#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>

class SystemTrayIcon : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemTrayIcon(QWidget *parent = 0);
    ~SystemTrayIcon();

    void CreatTrayMenu();
    void CreatTrayIcon();

    QSystemTrayIcon *myTrayIcon;

    QMenu *myMenu;

    QAction *miniSizeAction;
    QAction *maxSizeAction;
    QAction *restoreWinAction;
    QAction *quitAction;

public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void OnClickBubble();
protected:
    void closeEvent(QCloseEvent *event);

};

#endif // SYSTEMTRAYICON_H
