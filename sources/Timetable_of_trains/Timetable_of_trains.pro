TEMPLATE = subdirs

QMAKE_CXXFLAGS += -std=c++11

Console_for_timetable.depends = Core_of_timetable
Test_for_core.depends = Core_of_timetable

SUBDIRS += \
    Console_for_timetable \
    Core_of_timetable \
    Test_for_core \
    GUI_for_timetalbe
