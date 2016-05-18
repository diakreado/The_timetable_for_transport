#include "mainwindow.h"

MainWindow::MainWindow(CoreOfInfoAboutMetro* core) : core(core)
{
    routes_window = new RoutesWindow(core);
    routes_window->hide();

    choice_town_window = new ChoiceTown();
    choice_town_window->hide();

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




    QPushButton* button_choice_town = new QPushButton(this);

    button_choice_town->setStyleSheet(ButtonStyle);
    button_choice_town->setText("Выбрать город");
    button_choice_town->resize(180,50);
    button_choice_town->move(500,337);

    connect(button_choice_town,SIGNAL(clicked()),SLOT(openChoiceTown()));




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

void MainWindow::openChoiceTown()
{
    choice_town_window->show();
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



