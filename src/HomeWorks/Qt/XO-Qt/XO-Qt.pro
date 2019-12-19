Qt += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XO-Qt
TEMPLATE = app

HEADERS += \
    State.h \
    ai.h \
    board.h \
    game.h

SOURCES += \
    ai.cpp \
    board.cpp \
    game.cpp \
    main.cpp

RESOURCES += \
    resource.qrc
