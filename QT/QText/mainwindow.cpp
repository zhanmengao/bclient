#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolBar>
#include<QDockWidget>
QString course[7] = {"复变函数","数学分析","大学物理","大学体育","数值计算方法","概率论","运筹学"};
QString grade[7] = {"73","97","90","60","92","90","62"};
QString xuefen[7] = {"3.5","6","3","1","4.5","3","3"};
QString jidian[7] = {"复变函数","数学分析","大学物理","大学体育","数值计算方法","概率论","运筹学"};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    browser = new QTextBrowser(this);
    this->setCentralWidget(browser);
    QString str = "<table border='1' cellpadding='10'>"
                  " <tr>   <td>编号</td>   <td>课程名称</td>   <td>成绩</td>    <td>学分</td>   <td>绩点</td> </tr> "
                  " <tr>   <td> 1 </td>   <td>"+course[0]+"</td>   <td>"+grade[0]+"</td>    <td>"+xuefen[0]+"</td>   <td>"+jidian[0]+"</td> </tr> "
                                                                                                                                     " <tr>   <td> 2 </td>   <td>"+course[1]+"</td>   <td>"+grade[1]+"</td>    <td>"+xuefen[1]+"</td>   <td>"+jidian[1]+"</td> </tr> "
                                                                                                                                                                                                                                                        " <tr>   <td> 3 </td>   <td>"+course[2]+"</td>   <td>"+grade[2]+"</td>    <td>"+xuefen[2]+"</td>   <td>"+jidian[2]+"</td> </tr> "
                                                                                                                                                                                                                                                                                                                                                                           " <tr>   <td> 4 </td>   <td>"+course[3]+"</td>   <td>"+grade[3]+"</td>    <td>"+xuefen[3]+"</td>   <td>"+jidian[3]+"</td> </tr> "
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              " <tr>   <td> 5 </td>   <td>"+course[4]+"</td>   <td>"+grade[4]+"</td>    <td>"+xuefen[4]+"</td>   <td>"+jidian[4]+"</td> </tr> "
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 " <tr>   <td> 6 </td>   <td>"+course[5]+"</td>   <td>"+grade[5]+"</td>    <td>"+xuefen[5]+"</td>   <td>"+jidian[5]+"</td> </tr> "
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    " <tr>   <td> 7 </td>   <td>"+course[6]+"</td>   <td>"+grade[6]+"</td>    <td>"+xuefen[6]+"</td>   <td>"+jidian[6]+"</td> </tr> "
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       "</table> ";
    browser->insertHtml(str);

    QAction *emojiact = new QAction(QIcon(":/emoji/emoji/anguished-face_1f627.png"),tr("&Emoji"),this);
    emojiact->setShortcut(QKeySequence::New);       //快捷键
    emojiact->setStatusTip(tr("Emoji"));

    QAction *enteract = new QAction(QIcon(":/emoji/emoji/myicon_1.png"),tr("&Left"),this);
    enteract->setShortcut(QKeySequence::Print);       //快捷键
    enteract->setStatusTip(tr("Left"));

    QAction *rightact = new QAction(QIcon(":/emoji/editor.png"),tr("&Right"),this);
    rightact->setStatusTip(tr("Right"));

    //工具栏
    QToolBar *fileToolbar = addToolBar(tr("Tool"));
    fileToolbar->addAction(emojiact);
    fileToolbar->addAction(enteract);
    fileToolbar->addAction(rightact);

    //主窗口锚接空间
    QDockWidget *dock = new QDockWidget(tr("Edit"),this);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    edit = new QTextEdit(this);
    dock->setWidget(edit);
    addDockWidget(Qt::BottomDockWidgetArea,dock);            //给窗口添加Dock

    connect(emojiact,&QAction::triggered,this,&MainWindow::Emoji);
    connect(enteract,&QAction::triggered,this,&MainWindow::OnRecv);
    connect(rightact,&QAction::triggered,this,&MainWindow::OnEnter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Emoji()
{
    QString s1="<img width='15' height='15' "
               "src=':/emoji/emoji/anguished-face_1f627.png' "
               "style='float:left>";
    edit->insertHtml(s1);
}
void MainWindow::OnRecv()
{
    QString s1;
    QString ico = "':/emoji/emoji/myicon_1.png'";
    QString text = edit->toHtml();
    int len = edit->toPlainText().size();
    if(len>=23)
    {
        s1="<img width='30' height='30' "
           "src=" + ico +
                "style='float:left;margin-left:15px;margin-right:15px;'>"
                "<div "
                "style='background:rgb(205,215,226);padding-top:8px;float:left;"
                "margin-top:10px;"
                "margin-left:45px;padding:10px;"
                "margin-right:60px;'>"
                "<span style='font-size:15px;"
                "font-family:'Microsoft YaHei';margin-top:2px;'>"+text+"</span></div><br><br><br>";
    }
    else
    {
        QString rMargin=QString::number(60+(24-len)*15, 60);
        s1="<img width='30' height='30' "
           "src=" + ico +
                "style='float:left;margin-left:15px;margin-right:15px;'>"
                "<div "
                "style='background:rgb(205,215,226);padding-top:8px;float:left;"
                "margin-top:10px;"
                "margin-left:45px;padding:10px;"
                "margin-right:"+rMargin+"px;'>";

        s1+="<span style='font-size:15px;font-family:'Microsoft YaHei';"
            "margin-top:2px;'>"+text+"</span></div><br><br><br>";
    }
    browser->insertHtml(s1);
    browser->insertPlainText("\n");
    edit->clear();
    browser->moveCursor(QTextCursor::End);
}
void MainWindow::OnEnter()
{
    QString s1;
    QString text = edit->toPlainText();
    int len = edit->toPlainText().size();
    QString ico =  "':/emoji/editor.png'";
    if(len>=23)
    {
        s1="<img width='30' height='30' "
           "src=" + ico +
                "style='float:right;margin-left:15px;margin-right:15px;'>"
                "<div "
                "style='background:rgb(205,215,226);padding-top:8px;float:right;"
                "margin-top:10px;margin-right:45px;padding:10px;margin-left:60px;'>"
                "<span style='font-size:15px;text-align:right;line-height:3px;"
                "font-family:'Microsoft YaHei';margin-top:2px;'>"+text+"</span></div><br><br><br>";
    }
    else
    {
        QString rMargin=QString::number(60+(24-len)*15, 60);
        s1="<img width='30' height='30' "
           "src=" + ico +
                "style='float:right;margin-left:15px;margin-right:15px;'>"
                "<div "
                "style='background:rgb(205,215,226);padding-top:8px;float:right;"
                "margin-top:10px;margin-right:45px;padding:10px;"
                "margin-left:"+rMargin+"px;'>";

        s1+="<span style='font-size:15px;font-family:'Microsoft YaHei';text-align:right;line-height:3px;"
            "margin-top:2px;'>"+text+"</span></div><br><br><br>";
    }
    browser->insertHtml(s1);
    browser->insertPlainText("\n");
    edit->clear();
    browser->moveCursor(QTextCursor::End);
}
