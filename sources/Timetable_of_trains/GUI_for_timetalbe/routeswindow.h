#ifndef ROUTESWINDOW_H
#define ROUTESWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <core.h>
#include <QtCore/QVariant>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QGridLayout>


class RoutesWindow : public QWidget
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    QVector<QVector<QPushButton*>> stations_buttons_vector;

    QLabel* label;

public:

    RoutesWindow(CoreOfInfoAboutMetro* core);

private slots:

    void showStations();

    void showInfoAboutStation();
};

#endif // ROUTESWINDOW_H
