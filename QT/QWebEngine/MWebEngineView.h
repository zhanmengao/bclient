#ifndef SWEBENGINEVIEW_H
#define SWEBENGINEVIEW_H
#include <QWidget>
#include <QWebEngineView>
class MWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    explicit MWebEngineView(QWidget *parent = 0):QWebEngineView(parent)
    {

    }

    QList<QUrl> listUrl() const
    {
        return m_listUrl;
    }
    void addItemUrl(QUrl url)
    {
        m_listUrl << url;
    }
protected:
    /**
     * @brief createWindow 在鼠标左键点击的时候会触发这个方法
     * @param type
     * @return
     */
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override
    {
        qDebug("OnClick Open");
        Q_UNUSED(type);
        m_listUrl << this->url();
        return this;
    }
private:
    QList<QUrl> m_listUrl;
};
#endif // SWEBENGINEVIEW_H
