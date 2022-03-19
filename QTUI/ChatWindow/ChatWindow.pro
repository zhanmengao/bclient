QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    drawer.cpp \
    emotion.cpp \
    form.cpp \
    main.cpp \
    mychatwidget.cpp \
    mylistwidget.cpp \
    search.cpp \
    talk.cpp \
    two.cpp \
    wechat.cpp

HEADERS += \
    chat.h \
    drawer.h \
    emotion.h \
    form.h \
    mychatwidget.h \
    mylistwidget.h \
    search.h \
    talk.h \
    two.h \
    wechat.h

FORMS += \
    chat.ui \
    emotion.ui \
    form.ui \
    mainwindow.ui \
    mychatwidget.ui \
    mylistwidget.ui \
    search.ui \
    talk.ui \
    two.ui \
    wechat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    imagesrc.qrc \
    resource.qrc
