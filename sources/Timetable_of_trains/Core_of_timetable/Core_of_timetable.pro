#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T22:58:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core_of_timetable
TEMPLATE = lib

CONFIG += staticlib c++11

SOURCES += \
    core.cpp \
    file_handling/file_route_information.cpp \
    file_handling/file_station_information.cpp

HEADERS += \
    core.h \
    api.h \
    exception_of_core/exception_of_core.h \
    exception_of_core/station_does_not_exist.h \
    exception_of_core/route_does_not_exist.h \
    exception_of_core/there_are_no_routes.h \
    exception_of_core/item_does_not_exist.h \
    file_handling/file_handling.h \
    file_handling/file_route_information.h \
    file_handling/file_station_information.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
