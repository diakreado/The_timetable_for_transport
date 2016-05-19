#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include <QScrollBar>
#include <QVBoxLayout>
#include <core.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    CoreOfInfoAboutMetro core;

    QVector<QVector<QPushButton*>> stations_buttons_vector;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void showStations();

    void showInfoAboutStation();
};

#endif // MAINWINDOW_H
