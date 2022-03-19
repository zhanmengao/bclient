QT += widgets

HEADERS       = classwizard.h
SOURCES       = classwizard.cpp \
                main.cpp
RESOURCES     = classwizard.qrc

# install
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
