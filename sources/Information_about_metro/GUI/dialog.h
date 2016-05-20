#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <core.h>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    CoreOfInfoAboutMetro* core;

    int index;
    int* index_out_of;

public:
    Dialog(CoreOfInfoAboutMetro* core, int* index_out_of, QMainWindow* m_window, QWidget *parent = 0);
    ~Dialog();

signals:
    void deleteRouteSignal();

private slots:

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
