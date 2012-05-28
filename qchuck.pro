#-------------------------------------------------
#
# Project created by QtCreator 2012-05-28T09:23:32
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = qchuck
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    chucknorrisapi.cpp \
    joke.cpp \
    chuckapp.cpp

HEADERS += \
    chucknorrisapi.h \
    joke.h \
    chuckapp.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qjson/lib/release/ -lqjson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qjson/lib/debug/ -lqjson
else:mac: LIBS += -F$$PWD/qjson/lib/ -framework qjson
else:symbian: LIBS += -lqjson
else:unix: LIBS += -L$$PWD/qjson/lib/ -lqjson

INCLUDEPATH += $$PWD/qjson/include
DEPENDPATH += $$PWD/qjson/include
