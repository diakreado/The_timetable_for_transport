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

    int* index_out_of;
    QString* name_of_adding_station;

public:
    explicit DialogAboutAddingStationInRoute(CoreOfInfoAboutMetro* core,int* index_out_of,
                                             QString* name_of_adding_station,QMainWindow* m_window, QWidget *parent = 0);
    ~DialogAboutAddingStationInRoute();

signals:
    void addStationSignal();

private slots:

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_textEdit_textChanged();

private:
    Ui::DialogAboutAddingStationInRoute *ui;
};

#endif // DIALOGABOUTADDINGSTATIONINROUTE_H
