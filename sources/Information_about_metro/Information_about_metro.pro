TEMPLATE = subdirs

QMAKE_CXXFLAGS += -std=c++11

Console.depends = Core
GUI.depends = Core
Tests.depends = Core

SUBDIRS += \
    Core \
    Tests \
    Console \
    GUI
