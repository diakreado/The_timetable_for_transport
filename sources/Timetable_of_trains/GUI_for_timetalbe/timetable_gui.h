#ifndef TIMETABLEGUI_H
#define TIMETABLEGUI_H

#include <core.h>
#include "main_window.h"
#include <QApplication>

class TimetableGUI
{
public:

    TimetableGUI(int argc, char *argv[]);

    int startGUI();

    ~TimetableGUI();

private:

//    CoreOfInfoAboutMetro *core;

    int argc;
    char **argv;
};

#endif // TIMETABLEGUI_H
