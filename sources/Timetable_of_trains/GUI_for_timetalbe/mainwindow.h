#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "routeswindow.h"
#include <core.h>

class MainWindow : public QWidget
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    RoutesWindow* routes_window;

public:
    MainWindow(CoreOfInfoAboutMetro* core);

signals:

public slots:

    void openRouteInfo();

    void exit();
};

#endif // MAINWINDOW_H
