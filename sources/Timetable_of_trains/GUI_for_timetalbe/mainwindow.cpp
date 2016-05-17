#include "mainwindow.h"

MainWindow::MainWindow(CoreOfInfoAboutMetro* core) : core(core)
{
    routes_window = new RoutesWindow(core);
    routes_window->hide();

    QPixmap background(":/img/img/img1.jpg");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(qPalette);
    this->setFixedSize(730,525);
    this->setWindowTitle("Меню");

    QPushButton* button_to_route_info = new QPushButton(this);

    button_to_route_info->setStyleSheet("background-color: #66FF33; font-size: 13px;");
    button_to_route_info->setText("Открыть информацию \n о маршрутах");
    button_to_route_info->resize(180,50);
    button_to_route_info->move(500,317);

    connect(button_to_route_info,SIGNAL(clicked()),SLOT(openRouteInfo()));




    QPushButton* button_for_exit = new QPushButton(this);

    button_for_exit->setStyleSheet("background-color: #66FF33; font-size: 13px;");
    button_for_exit->setText("Выход");
    button_for_exit->resize(180,50);
    button_for_exit->move(500,417);

    connect(button_for_exit,SIGNAL(clicked()),SLOT(exit()));
}

void MainWindow::openRouteInfo()
{
    routes_window->show();
}

void MainWindow::exit()
{
    int n = QMessageBox::warning(0,
                                 "Предупреждение",
                                 "Вы уверенны, что хотите выйти?",
                                 "Да",
                                 "Нет",
                                 QString(),
                                 0,
                                 1
                                );
    if(!n) {this->close();}
}



