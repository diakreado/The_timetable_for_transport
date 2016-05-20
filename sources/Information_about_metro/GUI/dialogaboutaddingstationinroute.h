#ifndef DIALOGABOUTADDINGSTATIONINROUTE_H
#define DIALOGABOUTADDINGSTATIONINROUTE_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutAddingStationInRoute;
}

class DialogAboutAddingStationInRoute : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int *number_of_the_route;
    int *number_of_the_station;
    QString* new_name;

public:
    explicit DialogAboutAddingStationInRoute(CoreOfInfoAboutMetro* core, int *number_of_the_route,
                                             int *number_of_the_station, QString *new_name, QMainWindow* m_window,
                                             QWidget *parent = 0);
    ~DialogAboutAddingStationInRoute();

signals:
    void changeNameOfStation();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_clicked();

    void on_textEdit_textChanged();

private:
    Ui::DialogAboutAddingStationInRoute *ui;
};

#endif // DIALOGABOUTADDINGSTATIONINROUTE_H
