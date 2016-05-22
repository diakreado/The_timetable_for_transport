#ifndef DIALOGABOUTDELETINGINFOABOUTSTATION_H
#define DIALOGABOUTDELETINGINFOABOUTSTATION_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutDeletingInfoAboutStation;
}

class DialogAboutDeletingInfoAboutStation : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int *number_of_the_station;

public:
    explicit DialogAboutDeletingInfoAboutStation(CoreOfInfoAboutMetro* core, int *number_of_the_station, QMainWindow* m_window,QWidget *parent = 0);
    ~DialogAboutDeletingInfoAboutStation();

signals:
    void deleteInfoAboutStation();

private slots:
    void on_comboBox_2_activated(int index);
    void on_pushButton_clicked();

private:
    Ui::DialogAboutDeletingInfoAboutStation *ui;
};

#endif // DIALOGABOUTDELETINGINFOABOUTSTATION_H
