#ifndef DIALOGABOUTCHANGINGNAMEOFTHESTATIONS_H
#define DIALOGABOUTCHANGINGNAMEOFTHESTATIONS_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutChangingNameOfTheStations;
}

class DialogAboutChangingNameOfTheStations : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int *number_of_the_route;
    int *number_of_the_station;
    QString* new_name;


public:
    explicit DialogAboutChangingNameOfTheStations(CoreOfInfoAboutMetro* core, int *number_of_the_route,
                                                  int *number_of_the_station, QString *new_name, QMainWindow* m_window,
                                                  QWidget *parent = 0);
    ~DialogAboutChangingNameOfTheStations();

signals:
    void changeNameOfStation();

private slots:
    void on_comboBox_activated(int index);
    void on_comboBox_2_activated(int index);
    void on_pushButton_clicked();
    void on_textEdit_textChanged();

private:
    Ui::DialogAboutChangingNameOfTheStations *ui;
};

#endif // DIALOGABOUTCHANGINGNAMEOFTHESTATIONS_H
