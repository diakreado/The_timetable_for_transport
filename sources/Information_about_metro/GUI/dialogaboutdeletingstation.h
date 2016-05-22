#ifndef DIALOGABOUTDELETINGSTATION_H
#define DIALOGABOUTDELETINGSTATION_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutDeletingStation;
}

class DialogAboutDeletingStation : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int *number_of_the_route;
    int *number_of_the_station;

public:
    explicit DialogAboutDeletingStation(CoreOfInfoAboutMetro* core, int *number_of_the_route,
                                        int *number_of_the_station, QMainWindow* m_window, QWidget *parent = 0);
    ~DialogAboutDeletingStation();

signals:
    void deletingStation();

private slots:
    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::DialogAboutDeletingStation *ui;


};

#endif // DIALOGABOUTDELETINGSTATION_H
