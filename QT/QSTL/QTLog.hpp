#ifndef QTLOG_H
#define QTLOG_H
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
/*
qDebug : 调试信息提示
qWarning: 一般的警告提示
qCritical: 严重错误提示
qFatal: 致命错误提示
 */
void customMessageHandler(QtMsgType type,const QMessageLogContext& Context,const QString& msg)
{
    QString txt;
    switch (type)
    {
    //调试信息提示
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    //一般的warning提示
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    //严重错误提示
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    //致命错误提示
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        //abort();
        break;
    }
    printf("%s \n\r",txt.toStdString().c_str());
    QFile outFile("debuglog.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream ts(&outFile);
    ts << txt << endl;
}
void Load(const QString& fileName)
{
    QFile file(fileName);
    if(!file.exists())
    {
        qCritical("File '%s' does not exost!",qPrintable(fileName));    //危急消息
    }
}
void mainLog()
{
    //先注册自己的MsgHandler
    qInstallMessageHandler(customMessageHandler);
    Load("AAA");
    //以后就可以像下面这样直接打日志到文件中，而且日志也会包含时间信息
    qDebug("This is a debug message at thisisqt.com");
    qWarning("This is a warning message at thisisqt.com");
    qCritical("This is a critical message at thisisqt.com");
    //qFatal("This is a fatal message at thisisqt.com");
}
#endif // QTLOG_H
