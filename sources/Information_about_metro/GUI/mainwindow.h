#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QDialog>
#include <core.h>
#include "dialog.h"

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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void showStations();
    void showInfoAboutStation();
    void deleteRouteSlot();

    void on_action_2_triggered();
    void on_action_4_triggered();
};

#endif // MAINWINDOW_H
