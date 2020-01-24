QT       += core network
QT       -= gui

TARGET    = server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE  = app

SOURCES += main.cpp \
    Server.cpp \
    Application.cpp \
    Client.cpp \
    Field.cpp

HEADERS += \
    Server.h \
    Application.h \
    Client.h \
    Field.h \
    Constants.h
