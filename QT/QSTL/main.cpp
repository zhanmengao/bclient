#include <QCoreApplication>
#include"algorithm.hpp"
#include"QTLog.hpp"
#include<iostream>
#include"QBit.hpp"
#include"QByte.h"
#include"String.hpp"
#include"Compress.h"
#include"Date.hpp"
#include"RegExp.h"
#include"URL.hpp"
#include"Variant.hpp"
#include<HashMap.hpp>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //mainAl();
    //mainLog();
    //mainArray();
    //mainQByteArr();
    //ByteArrayMatcherMain();
    //StringMain();
    //QStringListMain();
    //QStringMatcherMain();
    //mainCompress();
    //DateMain();
    //QRegExpMain();
    //URLMain();
    //VariantMain();
    //HashMain();
    //MapMain();
    //QCharMain();
    //QLatin1StringMain();
    //QLocaleMain();
    //QstringSprit();
    substrMain();
    return a.exec();
}
