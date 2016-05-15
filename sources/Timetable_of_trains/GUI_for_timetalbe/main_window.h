#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <core.h>
#include <QObject>
#include <QtCore/QVariant>


class MainWindow : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE {1000, 600};
    const QSize BUTTON_SIZE { 180, 30 };

    CoreOfInfoAboutMetro* core;

     QVector<QVector<QPushButton*>> stations_buttons_vector;

public:

    MainWindow(QWidget *parent, CoreOfInfoAboutMetro* core);

private slots:

    void showStations();
};

#endif // MAINWINDOW_H
