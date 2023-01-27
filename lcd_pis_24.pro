QT       += core gui network printsupport multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
# CONFIG+=disable-desktop
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    WidgetMarqueeLabel.cpp \
    gpio_utils.cpp \
    main.cpp \
    mainwindow.cpp \
    rinfo.cpp \
    route.cpp \
    routedata.cpp \
    splashwindow.cpp \
    station.cpp

HEADERS += \
    WidgetMarqueeLabel.h \
    common.h \
    gpio_utils.h \
    mainwindow.h \
    rinfo.h \
    route.h \
    routedata.h \
    splashwindow.h \
    station.h

FORMS += \
    mainwindow.ui \
    splashwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/ir_logo.png \
    images/rtv_logo.png

RESOURCES += \
    resources.qrc
