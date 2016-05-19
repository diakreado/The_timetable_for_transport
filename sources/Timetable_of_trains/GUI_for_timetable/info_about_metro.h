#ifndef INFABOUTMETRO_H
#define INFABOUTMETRO_H

#include <QMainWindow>
#include <core.h>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QScrollBar>


class InfoAboutMetro : public QMainWindow
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    QLabel* info_about_station;

    QVector<QVector<QPushButton*>> stations_buttons_vector;

public:

    InfoAboutMetro(CoreOfInfoAboutMetro* core);

private slots:

      void addInfoAboutRoute();

      void showStations();

      void showInfoAboutStation();
};

#endif // INFABOUTMETRO_H
