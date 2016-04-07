#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T22:58:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core_of_timetable
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    file_route.cpp \
    core.cpp \
    file_timetable.cpp

HEADERS += \
    core.h \
    file_route.h \
    file.h \
    file_timetable.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
