#ifndef DIALOGABOUTADDINGINFOABOUTSTATION_H
#define DIALOGABOUTADDINGINFOABOUTSTATION_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutAddingInfoAboutStation;
}

class DialogAboutAddingInfoAboutStation : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int *number_of_the_route;
    int *number_of_the_station;
    QString* information_about_station;

public:
    explicit DialogAboutAddingInfoAboutStation(CoreOfInfoAboutMetro* core, int *number_of_the_route,
                                               int *number_of_the_station, QString *information_about_station, QMainWindow* m_window,
                                               QWidget *parent = 0);
    ~DialogAboutAddingInfoAboutStation();

signals:
    void addInformationAboutStation();

private slots:
    void on_comboBox_activated(int index);
    void on_comboBox_2_activated(int index);
    void on_pushButton_clicked();
    void on_textEdit_textChanged();

private:
    Ui::DialogAboutAddingInfoAboutStation *ui;
};

#endif // DIALOGABOUTADDINGINFOABOUTSTATION_H
