#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "routeswindow.h"
#include <core.h>
#include "choicetown.h"
#include "info_about_metro.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    RoutesWindow* routes_window;

    InfoAboutMetro* info_about_metro;

    QString ButtonStyle =  "QPushButton"
                           "{"
                               "background-color: #b7db70;"
                               "font-size: 13px;"
                               "border-radius: 20px;"
                               "font-weight: bold;"
                               "border: 2px solid #2e3d0f;"
                           "}"
                           "QPushButton:hover"
                           "{"
                               "background-color: #66FF33;"
                               "font-size: 13px;"
                               "border-radius: 20px;"
                               "font-weight: bold;"
                               "border: 1px solid #000000;"
                           "}"
                           "QPushButton:pressed"
                           "{"
                               "background-color: #6b8f24;"
                               "font-size: 13px;"
                               "border-radius: 20px;"
                               "font-weight: bold;"
                               "border: 1px solid #000000;"
                           "}";


public:
    MainWindow(CoreOfInfoAboutMetro* core);

signals:

private slots:

    void openRouteInfo();

    void openNewVariant();

    void exit();
};

#endif // MAINWINDOW_H
