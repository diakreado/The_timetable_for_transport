#include "mainwindow.h"

MainWindow::MainWindow(CoreOfInfoAboutMetro* core) : core(core)
{
    routes_window = new RoutesWindow(core);
    routes_window->hide();

    info_about_metro = new InfoAboutMetro(core);
    info_about_metro->hide();

    QPixmap background(":/img/img/img1.jpg");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(qPalette);
    this->setFixedSize(730,525);
    this->setWindowTitle("Меню");

    QPushButton* button_to_route_info = new QPushButton(this);

    button_to_route_info->setStyleSheet(ButtonStyle);
    button_to_route_info->setText("Открыть информацию \n о маршрутах");
    button_to_route_info->resize(180,50);
    button_to_route_info->move(500,277);

    connect(button_to_route_info,SIGNAL(clicked()),SLOT(openRouteInfo()));




    QPushButton* info_about_metro = new QPushButton(this);

    info_about_metro->setStyleSheet(ButtonStyle);
    info_about_metro->setText("Альтернативный вариант");
    info_about_metro->resize(180,50);
    info_about_metro->move(500,337);

    connect(info_about_metro,SIGNAL(clicked()),SLOT(openNewVariant()));




    QPushButton* button_for_exit = new QPushButton(this);

    button_for_exit->setStyleSheet(ButtonStyle);
    button_for_exit->setText("Выход");
    button_for_exit->resize(180,50);
    button_for_exit->move(500,397);

    connect(button_for_exit,SIGNAL(clicked()),SLOT(exit()));
}

void MainWindow::openRouteInfo()
{
    routes_window->show();
}

void MainWindow::openNewVariant()
{
    info_about_metro->show();
}

void MainWindow::exit()
{
    bool exit_or_not = QMessageBox::warning(0,
                                 "Предупреждение",
                                 "Вы уверенны, что хотите выйти?",
                                 "Да",
                                 "Нет",
                                 QString(),
                                 0,
                                 1
                                );
    if(!exit_or_not) {this->close();}
}



