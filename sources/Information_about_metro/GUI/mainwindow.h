#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QSize>
#include <QPoint>
#include <QRect>
#include <QTimer>
#include <QPainter>
#include <QPointF>
#include <QRadialGradient>
#include <QPen>
#include <QBrush>
#include <core.h>
#include "dialogaboutaddingstationinroute.h"
#include "dialogaboutdeletingroute.h"
#include "dialogaboutchangingnameofthestations.h"
#include "dialogaboutdeletingstation.h"
#include "dialogaboutaddinginfoaboutstation.h"
#include "dialogaboutdeletinginfoaboutstation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    CoreOfInfoAboutMetro core;

    QVector<QVector<QPushButton*>> stations_buttons_vector;
    QVector<QPushButton*> routes_buttons;

    QVBoxLayout* stations_layout;
    QVBoxLayout* routes_layout;

    int index;

    int number_of_the_route;
    int number_of_the_station;
    QString string_with_info;

    QString button_style = "QPushButton "
                           "{"
                           "border: 0px ;"
                           "border-radius: 9px;"
                           "background: #FFFFFF; "
                           "}"
                           "QPushButton:hover "
                           "{"
                               "border: 1px solid #bbbbbb;"
                           "}"
                           "QPushButton:pressed "
                           "{"
                               "border: 2px solid #4d4d4d;"
                           "}";

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void showStations();
    void showInfoAboutStation();
    void deleteRouteSlot();
    void changeNameOfStation();
    void addStation();
    void deletingStation();
    void addInformationAboutStation();
    void deleteInfoAboutStation();

    void on_action_2_triggered();
    void on_action_4_triggered();
    void on_action_9_triggered();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_10_triggered();
};

#endif // MAINWINDOW_H
