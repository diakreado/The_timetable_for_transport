#-------------------------------------------------
#
# Project created by QtCreator 2016-03-20T11:18:19
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_test_for_coretest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test_for_coretest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core_of_timetable/release/ -lCore_of_timetable
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core_of_timetable/debug/ -lCore_of_timetable
else:unix: LIBS += -L$$OUT_PWD/../Core_of_timetable/ -lCore_of_timetable

INCLUDEPATH += $$PWD/../Core_of_timetable
DEPENDPATH += $$PWD/../Core_of_timetable

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core_of_timetable/release/libCore_of_timetable.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core_of_timetable/debug/libCore_of_timetable.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core_of_timetable/release/Core_of_timetable.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core_of_timetable/debug/Core_of_timetable.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core_of_timetable/libCore_of_timetable.a
