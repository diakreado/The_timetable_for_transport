#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T17:10:19
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += \
    core.cpp \
    handling_info/parsing_info.cpp \
    handling_info/routes_info.cpp \
    handling_info/stations_info.cpp

HEADERS += \
    api.h \
    core.h \
    handling_info/parsing_info.h \
    handling_info/routes_info.h \
    handling_info/stations_info.h \
    exception_of_core/exception_of_core.h \
    exception_of_core/missing_file.h \
    exception_of_core/route_does_not_exist.h \
    exception_of_core/station_does_not_exist.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
