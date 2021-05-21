QT       += core gui charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainView.cpp \
    SerialReader.cpp \
    Structures.cpp \
    can_decodeparametersview.cpp \
    can_parser.cpp \
    datachartview.cpp \
    datalogger.cpp \
    main.cpp \
    newcan_decodeparametersdialog.cpp \
    serialportsettings.cpp

HEADERS += \
    MainView.h \
    SerialReader.h \
    Structures.h \
    can_decodeparametersview.h \
    can_parser.h \
    datachartview.h \
    datalogger.h \
    newcan_decodeparametersdialog.h \
    serialportsettings.h

FORMS += \
    MainView.ui \
    can_decodeparametersview.ui \
    datachartview.ui \
    newcan_decodeparametersdialog.ui \
    serialportsettings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/icon.ico \
    resources/icon.png

RC_ICONS = resources/icon.ico
