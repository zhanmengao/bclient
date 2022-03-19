#ifndef URL_HPP
#define URL_HPP
#include<QUrl>

void URLMain()
{
    QUrl url("http://www.example.com/List of holidays.xml");
    auto str = url.toEncoded();
    QUrl url2 = QUrl::fromEncoded("http://qt.nokia.com/List%20of%20holidays.xml");          //将编码的字符串构成URL
}
#endif // URL_HPP
