#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T17:47:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    dialogaboutaddingstationinroute.cpp \
    dialogaboutdeletingroute.cpp \
    dialogaboutchangingnameofthestations.cpp \
    dialogaboutdeletingstation.cpp \
    dialogaboutaddinginfoaboutstation.cpp \
    dialogaboutdeletinginfoaboutstation.cpp

HEADERS  += mainwindow.h \
    dialogaboutaddingstationinroute.h \
    dialogaboutdeletingroute.h \
    dialogaboutchangingnameofthestations.h \
    dialogaboutdeletingstation.h \
    dialogaboutaddinginfoaboutstation.h \
    dialogaboutdeletinginfoaboutstation.h

FORMS    += mainwindow.ui \
    dialogaboutaddingstationinroute.ui \
    dialogaboutdeletingroute.ui \
    dialogaboutchangingnameofthestations.ui \
    dialogaboutdeletingstation.ui \
    dialogaboutaddinginfoaboutstation.ui \
    dialogaboutdeletinginfoaboutstation.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/Core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/libCore.a
