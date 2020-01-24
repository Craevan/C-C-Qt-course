QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

CONFIG += static

SOURCES += \
    main.cpp\
    mainwindow.cpp \
    Field.cpp \
    Images.cpp \
    Model.cpp \
    Controller.cpp \
    Utility.cpp \
    ConnectionInfoDialog.cpp \
    AboutDialog.cpp \
    supportdialog.cpp

HEADERS += \
    AboutDialog.h \
    SupportDialog.h \
    mainwindow.h \
    Field.h \
    Images.h \
    Model.h \
    Controller.h \
    Utility.h \
    Defines.h \
    ConnectionInfoDialog.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

TRANSLATIONS += \
    russian.ts

langsRelease.commands = lrelease $${_PRO_FILE_}
QMAKE_EXTRA_TARGETS += langsRelease
PRE_TARGETDEPS += langsRelease
