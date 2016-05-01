#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T22:58:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core_of_timetable
TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    core.cpp \
    station_information.cpp \
    route_information.cpp

HEADERS += \
    core.h \
    api.h \
    station_information.h \
    route_information.h \
    file_handling.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
