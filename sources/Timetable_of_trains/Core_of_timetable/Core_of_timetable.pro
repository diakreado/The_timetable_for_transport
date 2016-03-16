#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T22:58:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core_of_timetable
TEMPLATE = lib
CONFIG += staticlib

SOURCES += core_of_timetable.cpp \
    train.cpp

HEADERS += core_of_timetable.h \
    train.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
