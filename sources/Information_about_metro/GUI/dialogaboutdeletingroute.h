#ifndef DIALOGABOUTDELETINGROUTE_H
#define DIALOGABOUTDELETINGROUTE_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class DialogAboutDeletingRoute;
}

class DialogAboutDeletingRoute : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int* index_out_of;

public:
    explicit DialogAboutDeletingRoute(CoreOfInfoAboutMetro* core, int* index_out_of, QMainWindow* m_window, QWidget *parent = 0);
    ~DialogAboutDeletingRoute();

signals:
    void deleteRouteSignal();

private slots:

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();


private:
    Ui::DialogAboutDeletingRoute *ui;
};

#endif // DIALOGABOUTDELETINGROUTE_H
