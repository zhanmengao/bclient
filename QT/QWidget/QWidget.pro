
QT       += core gui

TARGET = QWidget
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        dialog.cpp \
        widget.cpp

HEADERS  += widget.h \
    dialog.h

RESOURCES += \
    resources.qrc

FORMS += \
    dialog.ui
